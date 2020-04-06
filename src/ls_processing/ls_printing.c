/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 19:31:07 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_default_print(t_list *lst)
{
	t_basic		*basic;
	t_list		*lstc;

	lstc = lst;
	while (lstc)
	{
		basic = (t_basic*)lstc->content;
		ft_printf("%s\n", basic->name.name);
		lstc = lstc->next;
	}
}

void		ls_printing(t_list *lst, t_paddings *pads)
{
	t_uint	index;
	t_uint	print_select_flags;

	print_select_flags = ls_get_group_active_flags(PRINT_SELECT_GROUP);
	index = 0;
	while (index < SORT_SELECT_FLAGS_C)
	{
		if (print_select_flags & (1 << index))
		{
			g_print_select_func[index](lst, pads);
			return ;
		}
		index++;
	}
	ls_default_print(lst);
}
