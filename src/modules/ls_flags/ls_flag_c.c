/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:43:35 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/03 22:38:38 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_c(struct stat *istat, t_basic *basic, void *res)
{
	if (!res)
		res = NULL;
	basic->date.time = istat->st_ctimespec;
}
