/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/19 23:13:16 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ls_parse_directory(char *directory)
{
	DIR				*dirstream;
	struct dirent	*dirent;
	size_t			dir_count;

	dirstream = opendir(directory);
	dir_count = 0;
	while ((dirent = readdir(dirstream)))
		dir_count += ls_parse_entry(dirent->d_name) ? 1 : 0;
	closedir(dirstream);
}

t_bool	ls_parse_entry(char *entry)
{
	struct stat		istat;

	if(stat(entry, &istat) == -1)
		perror(entry);
	return (S_ISDIR(istat.st_mode));
}
