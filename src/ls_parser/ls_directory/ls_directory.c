/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/03 23:37:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_space_paddings(t_basic *info, t_paddings *pads)
{
	pads->links = ft_umax(info->links.linksl, pads->links);
	pads->usr = ft_umax(info->owner.usrl, pads->usr);
	pads->grp = ft_umax(info->owner.grpl, pads->grp);
	pads->size = ft_umax(info->size.sizel, pads->size);
}

static t_bool	ls_file_process(struct dirent *stream)
{
	t_uint	index;
	t_uint	file_select_flags;
	t_bool	res;

	file_select_flags = ls_get_group_active_flags(GROUP_FILE_SELECT);
	index = 0;
	res = stream->d_name[0] != '.';
	while (index < g_groups_counts[GROUP_FILE_SELECT])
	{
		if (file_select_flags & (1 << index))
		{
			g_file_select_func[index](stream, &res);
			return (res);
		}
		index++;
	}
	return (res);
}

static void		ls_parse_item(char *path,
	char *name,
	t_paddings *pads,
	t_list **lst)
{
	t_basic				*entry;

	entry = NULL;
	entry = ls_parse_entry(path, name);
	if (entry == NULL)
		return ;
	ls_space_paddings(entry, pads);
	ft_lstadd(lst, ft_lstnewp(entry, sizeof(entry)));
}

static t_bool	ls_sort_default(void *entry1, void *entry2)
{
	t_basic	*a;
	t_basic	*b;

	a = (t_basic*)entry1;
	b = (t_basic*)entry2;
	return (ft_strcmp(a->name.name, b->name.name) > 0);
}

t_list			*ls_directory(char *dir)
{
	t_dir				curd;
	t_list				*lst;
	static t_paddings	pads;

	lst = NULL;
	curd.stream = opendir(dir);
	curd.len = ft_strlen(dir);
	ft_strlcpy(dir + curd.len++, "/", 1);
	while ((curd.ent = readdir(curd.stream)))
	{
		if (!ls_file_process(curd.ent))
			continue ;
		ft_strlcpy(dir + curd.len, curd.ent->d_name, PATH_MAX);
		ls_parse_item(dir, curd.ent->d_name, &pads, &lst);
	}
	closedir(curd.stream);
	ft_bzero(dir + curd.len - 1, PATH_MAX - curd.len - 1);
	ft_list_bubble_sort(&lst, &ls_sort_default);
	ls_print(lst, &pads);
	return (lst);
}
