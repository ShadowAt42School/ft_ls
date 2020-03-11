/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_big_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:46:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/09 23:02:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_big_r(char *path_parse)
{
	char			**directories;
	static char		path[PATH_MAX + 1];
	size_t			path_len;

	path_len = ft_strlen(path_parse);
	ft_memcpy(path, path_parse, path_len);
	directories = NULL;
	ls_parse_directory(path, FALSE, &directories);
	ft_memcpy(path + path_len, "/", 1);
	while (*directories)
	{
		ft_printf("\n%s:\n", path);
		ft_memcpy(path + path_len + 1, *directories, PATH_MAX);
		ls_flag_big_r(path);
		directories++;
	}
	ft_bzero(path + path_len, PATH_MAX);
}
