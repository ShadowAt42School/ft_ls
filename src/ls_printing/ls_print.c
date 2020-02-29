/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:04:08 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 04:17:59 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print(t_list *lst)
{
	t_basic		*info;

	while(lst)
	{
		info = (t_basic*)lst->content;
		if (ls_parse_long_listing())
			ft_printf("%c%s %s %u %u %s %s %s\n",
			info->access.type,
			info->access.permissions,
			info->links.links,
			info->owner.st_uid,
			info->owner.st_gid,
			info->size.size,
			"date",
			info->name.name);
		lst = lst->next;
	}
}
