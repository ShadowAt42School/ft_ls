/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:30:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/18 22:13:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_parse_engine(char *directory)
{
	DIR				*dirstream;
	struct dirent	*dirent;

	ft_printf("%s\n", directory);
	dirstream = opendir(directory);
	while ((dirent = readdir(dirstream)))
		ft_printf("%s\n", dirent->d_name);
}

void			ls_engine()
{
	static char 	*argument;

	ls_flags_parse();
	while ((argument = cl_get_argument()))
		ls_parse_engine(argument);
}
