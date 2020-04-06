/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:30:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 13:30:43 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_parse_engine(char *path)
{
	struct stat		item;

	if (lstat(path, &item) == -1)
		perror(path);
	if (S_ISDIR(item.st_mode))
	{
		if (ls_is_flag(FLAG_BR))
		{
			ls_flag_big_r(path);
			return ;
		}
		ls_parse_directory(path, FALSE, NULL);
	}
	else
	{
		ls_parse_entry(path, path);
	}
}

static t_bool	ls_arguments_sort(char *argum1, char *argum2)
{
	struct stat		istat1;
	struct stat		istat2;

	if (ls_is_flag(FLAG_BH))
	{
		stat(argum1, &istat1);
		stat(argum2, &istat2);
	}
	else
	{
		lstat(argum1, &istat1);
		lstat(argum2, &istat2);
	}
	if (S_ISDIR(istat1.st_mode) && S_ISDIR(istat2.st_mode))
		return (ft_strcmp(argum1, argum2) > 0);
	else if (!S_ISDIR(istat1.st_mode) && !S_ISDIR(istat2.st_mode))
		return (ft_strcmp(argum1, argum2) > 0);
	else if (!S_ISDIR(istat1.st_mode) && S_ISDIR(istat2.st_mode))
		return (FALSE);
	else if (S_ISDIR(istat1.st_mode) && !S_ISDIR(istat2.st_mode))
		return (TRUE);
	return (FALSE);
}

void			ls_engine(void)
{
	static char		*argument;
	static char		path[PATH_MAX + 1];

	ls_flags_parse();
	cl_sort_arguments(&ls_arguments_sort);
	while ((argument = cl_get_argument()))
	{
		ft_memcpy(path, argument, ft_strlen(argument));
		ls_parse_engine(path);
	}
}
