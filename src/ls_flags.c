/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:28:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/19 21:56:18 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_uint	g_flags;

void	ls_flags_parse()
{
	t_option		*option;
	t_uint			flags;
	unsigned char	index;

	flags = 0;
	index = 0;
	while (index < FLAGS_COUNT)
	{
		if ((option = cl_get_sopt(FLAGS_STR[index])))
			flags |= (1 << (index));
		index++;
	}
	g_flags = flags;
}

t_bool	ls_is_flag(t_uint flag)
{
	t_bool d = ((g_flags & flag) == flag);
	return (d);
}

void	ls_disable_flag(t_uint flag)
{
	g_flags &= flag;
}