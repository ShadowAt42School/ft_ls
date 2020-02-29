/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:30:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 03:43:30 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_parse_engine(char *path)
{
	struct stat		item;

	if (stat(path, &item) == -1)
		perror(path);
	if (S_ISDIR(item.st_mode))
		ls_parse_directory(path);
	else
		ls_parse_entry(path, path);
}

void			ls_engine(void)
{
	static char		*argument;
	static char		path[PATH_MAX + 1];

	ls_flags_parse();
	// add argument sorting
	while ((argument = cl_get_argument()))
	{
		ft_memcpy(path, argument, ft_strlen(argument));
		ls_parse_engine(path);
	}
}
