/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/26 22:17:39 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool	ls_process_a(struct dirent *ent)
{
	if (!ls_is_flag(FLAG_A) && ent->d_name[0] == '.')
		return (FALSE);
	return (TRUE);
}
