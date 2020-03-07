/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/06 19:50:55 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_directory.h"

static t_bool	ls_sort_entry_default(void *entry1, void *entry2, t_bool is_rev)
{
	t_basic	*a;
	t_basic	*b;

	a = (t_basic*)entry1;
	b = (t_basic*)entry2;
	if (is_rev)
		return (ft_strcmp(a->name.name, b->name.name) < 0);
	return (ft_strcmp(a->name.name, b->name.name) > 0);
}

static void		ls_directory_sort(t_list *lst)
{
	t_uint	index;
	t_uint	sort_select_flags;

	sort_select_flags = ls_get_group_active_flags(SORT_SELECT_GROUP);
	index = 0;
	while (index < SORT_SELECT_FLAGS_C)
	{
		if (sort_select_flags & (1 << index))
		{
			g_sort_select_func[index](lst, ls_is_flag(FLAG_R));
			return ;
		}
		index++;
	}
	ft_list_bubble_sort(&lst, ls_is_flag(FLAG_R), &ls_sort_entry_default);
}

static void		ls_default_print(t_list *lst)
{
	t_basic		*basic;
	t_list		*lstc;

	lstc = lst;
	while (lstc)
	{
		basic = (t_basic*)lstc->content;
		ft_printf("%s\n", basic->name.name);
		lstc = lstc->next;
	}
}

static void		ls_directory_entry_rep(t_list *lst, t_paddings *pads)
{
	t_uint	index;
	t_uint	print_select_flags;
	t_list	*lstc;

	lstc = lst;
	print_select_flags = ls_get_group_active_flags(PRINT_SELECT_GROUP);
	index = 0;
	while (index < SORT_SELECT_FLAGS_C)
	{
		if (print_select_flags & (1 << index))
		{
			while (lstc)
			{
				g_print_select_func[index](lstc->content, pads);
				lstc = lstc->next;
			}
			return ;
		}
		index++;
	}
	ls_default_print(lst);
}

void			*ls_directory(char *dir, t_paddings *pads)
{
	t_dir		curd;
	t_basic		*item;
	t_list		*lst;

	lst = NULL;
	curd.stream = opendir(dir);
	curd.len = ft_strlen(dir);
	ft_strlcpy(dir + curd.len++, "/", 1);
	while ((curd.ent = readdir(curd.stream)))
	{
		ft_strlcpy(dir + curd.len, curd.ent->d_name, curd.ent->d_namlen);
		if (!(item = ls_parse_dir_file(dir, curd.ent, pads)))
			continue ;
		ft_lstadd(&lst, ft_lstnewp(item, 0));
	}
	closedir(curd.stream);
	ft_bzero(dir + curd.len - 1, PATH_MAX - curd.len - 1);
	ls_directory_sort(lst);
	ls_directory_entry_rep(lst, pads);
	return (lst);
}
