/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:46:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/05 23:05:03 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char const **argv)
{
	t_option	options[FLAGS_COUNT + 1];

	argc--;
	argv++;
	options[FLAG_L] = (t_option){.shortc = 'l'};
	options[FLAG_BR] = (t_option){.shortc = 'R'};
	options[FLAG_A] = (t_option){.shortc = 'a'};
	options[FLAG_R] = (t_option){.shortc = 'r'};
	options[FLAG_T] = (t_option){.shortc = 't'};
	options[FLAG_C] = (t_option){.shortc = 'c'};
	options[FLAG_BA] = (t_option){.shortc = 'A'};
	cl_init((char **)argv, options, FLAGS_COUNT + 1);
	ls_engine();
	return (0);
}
