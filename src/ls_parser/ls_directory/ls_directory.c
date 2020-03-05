/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 23:15:38 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_directory.h"

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

	file_select_flags = ls_get_group_active_flags(FILE_SELECT_GROUP);
	index = 0;
	res = stream->d_name[0] != '.';
	while (index < g_groups_counts[FILE_SELECT_GROUP])
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

void			*ls_directory(char *dir, t_paddings *pads)
{
	t_dir				curd;
	t_list				*lst;

	lst = NULL;
	curd.stream = opendir(dir);
	curd.len = ft_strlen(dir);
	ft_strlcpy(dir + curd.len++, "/", 1);
	while ((curd.ent = readdir(curd.stream)))
	{
		if (!ls_file_process(curd.ent))
			continue ;
		ft_strlcpy(dir + curd.len, curd.ent->d_name, PATH_MAX);
		ls_parse_item(dir, curd.ent->d_name, pads, &lst);
	}
	closedir(curd.stream);
	ft_bzero(dir + curd.len - 1, PATH_MAX - curd.len - 1);
	return (lst);
}
