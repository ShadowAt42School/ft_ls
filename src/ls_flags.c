/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:28:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/22 22:17:54 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_uint	g_flags;

void	ls_flags_parse()
{
	t_option		*option;
	unsigned char	index;

	index = 0;
	while (index < FLAGS_COUNT)
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
