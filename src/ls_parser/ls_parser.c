/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/28 00:16:09 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_parse_directory(char *dir)
{
	DIR				*dir_stream;
	struct dirent	*dirent;
	t_uint			dir_len;
	t_basic			*entries;
	t_list			*lst;

	dir_stream = opendir(dir);
	dir_len = ft_strlen(dir);
	if (*(dir + dir_len - 1) != '/')
		ft_strlcpy(dir + dir_len++, "/", 1);
	while ((dirent = readdir(dir_stream)))
	{
		if (!ls_dir_processing(dirent))
			continue ;
		ft_strlcpy(dir + dir_len, dirent->d_name, PATH_MAX);
		entries = ls_parse_entry(dir, dirent->d_name);
		if (entries == NULL)
			continue ;
		ft_lstadd(&lst, ft_lstnewp(entries, sizeof(entries)));
	}
	closedir(dir_stream);
	ft_bzero(dir + dir_len - 1, PATH_MAX - dir_len - 1);
}

t_basic		*ls_parse_entry(char *entry, char *name)
{
	struct stat		istat;
	t_basic			*info;

	info = ft_calloc(1, sizeof(t_basic));
	info->name.name = ft_strdup(name);
	if (stat(entry, &istat) == -1)
		perror(entry);
	ls_parse_permissions(&istat, info);
	info->links = istat.st_nlink;
	ls_parse_access(&istat, info);
	ls_parse_size(&istat, info);
	ls_parse_owner(&istat, info, FALSE);
	return (info);
}
