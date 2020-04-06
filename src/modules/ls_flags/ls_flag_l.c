/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:37:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/02 21:16:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

# define REGULAR_FMT "%c%s%c %*u %-*s %-*s %*s %s %s%c%s\n"
# define MAJOR_MIOR_FMT "%c%s%c %*u %-*s %-*s %3u, %3u %s %s%c%s\n"
# define MAJOR_MIOR_HEX_FMT "%c%s%c %*u %-*s %-*s %3u, %#010x %s %s%c%s\n"

static void		ls_flag_l_parse_spec(t_basic *basic, t_paddings *pads)
{
	ft_printf(basic->size.minor > 255 ? MAJOR_MIOR_HEX_FMT : MAJOR_MIOR_FMT,
	basic->access.type,
	basic->access.permissions,
	basic->access.extra,
	pads->links,
	basic->links.links,
	pads->usr + 1,
	basic->owner.usr,
	pads->grp + 1,
	basic->owner.grp,
	basic->size.major,
	basic->size.minor,
	basic->date.rep,
	basic->name.name,
	basic->name.marking,
	basic->name.pname.name);
}

static void		ls_flag_l_parse(t_basic *basic, t_paddings *pads)
{
	if (basic->size.is_spec)
	{
		ls_flag_l_parse_spec(basic, pads);
		return ;
	}
	ft_printf(REGULAR_FMT,
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
