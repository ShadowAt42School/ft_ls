/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:43:35 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 23:52:59 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_bool	ls_timestamp_sort(void *entry1, void *entry2, t_bool reverse)
{
	t_basic	*a;
	t_basic	*b;

	a = (t_basic*)entry1;
	b = (t_basic*)entry2;
	if (reverse)
	{
		if (a->date.time.tv_sec == b->date.time.tv_sec)
			return (ft_strcmp(a->name.name, b->name.name) < 0);
		return (a->date.time.tv_sec > b->date.time.tv_sec);
	}
	if (a->date.time.tv_sec == b->date.time.tv_sec)
		return (ft_strcmp(a->name.name, b->name.name) > 0);
	return (a->date.time.tv_sec < b->date.time.tv_sec);
}

void			ls_flag_t(t_list *lst, t_bool reverse)
{
	ft_list_bubble_sort(&lst, reverse, &ls_timestamp_sort);
}
