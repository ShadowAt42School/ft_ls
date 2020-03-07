/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:45:13 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/06 19:12:07 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_directory.h"

static void		ls_space_paddings(t_basic *info, t_paddings *pads)
{
	pads->links = ft_umax(info->links.linksl, pads->links);
	pads->usr = ft_umax(info->owner.usrl, pads->usr);
	pads->grp = ft_umax(info->owner.grpl, pads->grp);
	pads->size = ft_umax(info->size.sizel, pads->size);
	pads->count++;
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

static t_basic	*ls_file(char *path,
	char *name,
	t_paddings *pads)
{
	t_basic				*entry;

	entry = NULL;
	entry = ls_parse_entry(path, name);
	if (entry == NULL)
		return (NULL);
	ls_space_paddings(entry, pads);
	return (entry);
}

t_basic			*ls_parse_dir_file(char *dir,
										struct dirent *ent, t_paddings *pads)
{
	if (!ls_file_process(ent))
		return (NULL);
	return (ls_file(dir, ent->d_name, pads));
}
