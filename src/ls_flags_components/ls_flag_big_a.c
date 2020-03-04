/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_big_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/03 23:42:54 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_big_a(struct dirent *ent, void *res)
{
	if ((ent->d_name[0] == '.' && ent->d_name[1] == '\0')
		|| (ent->d_name[0] == '.'
			&& ent->d_name[0] == '.'
			&& ent->d_name[2] == '\0'))
	{
		*((t_bool*)res) = FALSE;
		return ;
	}
	*((t_bool*)res) = TRUE;
}
