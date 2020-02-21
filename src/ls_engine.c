/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:30:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/20 22:23:40 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_parse_engine(char *item)
{
	struct stat		root_item;

	if(stat(item, &root_item) == -1)
		perror(item);
	if (S_ISDIR(root_item.st_mode))
		ls_parse_directory(item);
	else
		ls_parse_entry(item);
}

void			ls_engine()
{
	static char 	*argument;
	static char		path[PATH_MAX + 1];

	ls_flags_parse();
	while ((argument = cl_get_argument()))
	{
		ft_memcpy(path, argument, ft_strlen(argument));
		ls_parse_engine(path);
	}
}
