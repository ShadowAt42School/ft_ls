/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:41:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/26 00:44:57 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	ls_dir_entry_count(DIR *dir_stream)
{
	size_t	count;

	count = 0;
	while (readdir(dir_stream))
		count++;
	rewinddir(dir_stream);
	return (count);
}


void	ls_parse_directory(char *dir)
{
	DIR				*dir_stream;
	struct dirent	*dirent;
	t_uint			dir_len;
	t_basic			*entries;

	dir_stream = opendir(dir);
	entries = ft_calloc(ls_dir_entry_count(dir_stream) + 1, sizeof(t_basic*));
	dir_len = ft_strlen(dir);
	if (*(dir + dir_len - 1) != '/')
		ft_strlcpy(dir + dir_len++, "/", 1);
	while ((dirent = readdir(dir_stream)))
	{
		// if (!ls_dir_processing(dirent))
		// 	continue ;
		ft_strlcpy(dir + dir_len, dirent->d_name, PATH_MAX);
		entries = ls_parse_entry(dir);
		entries++;
	}
	closedir(dir_stream);
	ft_bzero(dir + dir_len - 1, PATH_MAX - dir_len - 1);
}
