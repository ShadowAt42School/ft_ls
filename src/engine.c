/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:30:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/17 19:49:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

void	ls_engine()
{
	unsigned int	flags;

	ls_engine_parse_flags(&flags);
}

void ls_engine_parse_flags(unsigned int *flags)
{
	t_option		*option;
	unsigned char	index;

	*flags = 0;
	index = 0;
	while (index < 5)
	{
		if ((option = cl_get_sopt(FLAGS_STR[index])))
			*flags |= (1 << (index));
		index++;
	}
	ft_printf("%u\n", *flags);
}
