/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/06 19:47:15 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_flag_l(t_basic *basic, t_paddings *pads)
{
	ft_printf("%c%s%c %*u %-*s %-*s %*s %s %s\n",
	basic->access.type,
	basic->access.permissions,
	basic->access.extra,
	pads->links,
	basic->links.links,
	basic->owner.usrl + 1,
	basic->owner.usr,
	basic->owner.grpl + 1,
	basic->owner.grp,
	pads->size,
	basic->size.rep,
	basic->date.rep,
	basic->name.name);
}
