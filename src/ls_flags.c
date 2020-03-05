/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:28:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 23:32:33 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_uint	g_flags;

t_uint	ls_get_group_active_flags(t_uint group_id)
{
	t_uint	res;
	t_uint	index;

	index = 0;
	res = 0;
	while (index < g_groups_counts[group_id])
	{
		if (ls_is_flag(g_groups[group_id][index]))
			res |= (1 << index);
		index++;
	}
	return (res);
}

void	ls_flags_parse(void)
{
	t_option		*option;
	unsigned char	index;

	index = 0;
	while (index < (FLAGS_COUNT + 1))
	{
		if ((option = cl_get_sopt(FLAGS_STR[index])) && option->is_set)
			g_flags |= (1 << index);
		index++;
	}
}

t_bool	ls_is_flag(t_uint flag)
{
	return ((g_flags & (1 << flag)) == (1 << flag));
}

void	ls_disable_flag(t_uint flag)
{
	g_flags &= ~(1 << flag);
}
