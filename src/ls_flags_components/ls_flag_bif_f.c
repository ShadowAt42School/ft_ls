/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_bif_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:43:35 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/09 21:52:08 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_big_f(struct stat *istat, t_basic *basic, void *res)
{
	if (res == NULL)
		res = NULL;
	if (S_ISDIR(istat->st_mode))
		basic->name.marking = '/';
	else if (S_ISFIFO(istat->st_mode))
		basic->name.marking = '|';
	else if (S_ISLNK(istat->st_mode))
		basic->name.marking = '@';
	else if (S_ISSOCK(istat->st_mode))
		basic->name.marking = '=';
	else if (basic->access.permissions[2] == 'x' ||
		basic->access.permissions[5] == 'x' ||
		basic->access.permissions[8] == 'x')
		basic->name.marking = '*';
}
