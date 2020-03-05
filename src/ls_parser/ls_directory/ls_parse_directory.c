/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:48:51 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 23:52:42 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_directory.h"

static void		ls_recursive_process(t_list *lst)
{
	t_list	*run;

	run = lst;
	return ;
}

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

void			ls_parse_directory(char *dir, t_bool is_recursive)
{
	t_list		*lst;
	t_paddings	pads;

	is_recursive = FALSE;
	ft_bzero(&pads, sizeof(t_paddings));
	lst = ls_directory(dir, &pads);
	ls_directory_sort(lst);
	ls_print(lst, &pads);
	if (is_recursive)
		ls_recursive_process(lst);
}
