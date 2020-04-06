/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 19:28:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_bool	ls_sort_default(void *entry1, void *entry2, t_bool is_rev)
{
	t_basic	*a;
	t_basic	*b;

	a = (t_basic*)entry1;
	b = (t_basic*)entry2;
	if (is_rev)
		return (ft_strcmp(a->name.name, b->name.name) < 0);
	return (ft_strcmp(a->name.name, b->name.name) > 0);
}

void		ls_sort(t_list *lst)
{
	t_bool	is_rev;
	t_uint	index;
	t_uint	sort_select_flags;

	is_rev = ls_is_flag(FLAG_R);
	sort_select_flags = ls_get_group_active_flags(SORT_SELECT_GROUP);
	index = 0;
	while (index < SORT_SELECT_FLAGS_C)
	{
		if (sort_select_flags & (1 << index))
		{
			g_sort_select_func[index](lst, is_rev);
			return ;
		}
		index++;
	}
	ft_list_bubble_sort(&lst, is_rev, &ls_sort_default);
}
