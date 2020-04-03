/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/25 22:02:17 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_a(struct dirent *ent, void *res)
{
	t_bool	*e;

	e = (t_bool*)res;
	if (ent->d_name[0] == '.')
	{
		*e = TRUE;
		return ;
	}
}
