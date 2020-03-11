/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/10 20:49:42 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_flag_l_parse(t_basic *basic, t_paddings *pads)
{
	ft_printf("%c%s%c %*u %-*s %-*s %*s %s %s%c%s\n",
	basic->access.type,
	basic->access.permissions,
	basic->access.extra,
	pads->links,
	basic->links.links,
	pads->usr + 1,
	basic->owner.usr,
	pads->grp + 1,
	basic->owner.grp,
	pads->size,
	basic->size.rep,
	basic->date.rep,
	basic->name.name,
	basic->name.marking,
	basic->name.pname.name);
}

void			ls_flag_l(t_list *lst, t_paddings *pads)
{
	ft_printf("total %u\n", pads->total_blocks);
	while (lst)
	{
		ls_flag_l_parse(lst->content, pads);
		lst = lst->next;
	}
}
