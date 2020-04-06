/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 20:25:08 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ls_directory_len(char *dpath)
{
	DIR		*stream;
	size_t	dcount;

	dcount = 0;
	stream = opendir(dpath);
	if (stream)
	while (/* condition */) {
		/* code */
	}
}

void		*ls_directory(char *dir, t_paddings *pads)
{
	t_dir		curd;
	t_basic		*item;
	t_list		*lst;

	lst = NULL;
	ft_bzero(&curd, sizeof(t_dir));
	curd.stream = opendir(dir);
	curd.len = ft_strlen(dir);
	ft_strlcpy(dir + curd.len++, "/", 1);
	while ((curd.ent = readdir(curd.stream)))
	{
		ft_strlcpy(dir + curd.len, curd.ent->d_name, curd.ent->d_namlen);
		if (!(item = ls_parse_dir_file(dir, curd.ent, pads)))
			continue ;
		pads->total_blocks += item->size.blks;
		ft_lstadd(&lst, ft_lstnewp(item, 0));
	}
	closedir(curd.stream);
	ft_bzero(dir + curd.len - 1, PATH_MAX - curd.len - 1);
	return (lst);
}
