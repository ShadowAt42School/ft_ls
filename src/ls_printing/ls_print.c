/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:04:08 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/03 22:28:49 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print(t_list *lst, t_paddings *pads)
{
	t_basic		*info;

	while (lst)
	{
		info = (t_basic*)lst->content;
		if (ls_parse_long_listing())
			ft_printf("%c%s%c %*u %-*s %-*s %*s %s %s\n",
			info->access.type,
			info->access.permissions,
			info->access.extra,
			pads->links,
			info->links.links,
			info->owner.usrl + 1,
			info->owner.usr,
			info->owner.grpl + 1,
			info->owner.grp,
			pads->size,
			info->size.rep,
			info->date.rep,
			info->name.name);
		else
			ft_printf("%s\n", info->name.name);
		lst = lst->next;
	}
}
