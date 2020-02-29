/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 03:39:29 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool	ls_parse_long_listing(void)
{
	size_t	counter;

	counter = 0;
	while (counter < FDETAILS_COUNT)
	{
		if (ls_is_flag(g_flag_fdetails[counter]))
			return (TRUE);
		counter++;
	}
	return (FALSE);
}

void	ls_parse_access(struct stat *istat, t_basic *basic)
{
	ft_strcpy(basic->access.permissions, "---------");
	basic->access.type = '-';
	ls_parse_type(istat, basic);
	ls_parse_permissions(istat, basic);
}

void	ls_parse_name(struct stat *stat, t_basic *basic)
{
	if (S_ISDIR(stat->st_mode))
		basic->name.marking = '/';
	else if (S_ISFIFO(stat->st_mode))
		basic->name.marking = '|';
	else if (S_ISLNK(stat->st_mode))
		basic->name.marking = '@';
	else if (S_ISSOCK(stat->st_mode))
		basic->name.marking = '=';
	else if (basic->access.permissions[2] == 'x' ||
		basic->access.permissions[5] == 'x' ||
		basic->access.permissions[8] == 'x')
		basic->name.marking = '*';
}
