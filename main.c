/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:46:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 02:57:58 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char const **argv)
{
	t_option	options[FLAGS_COUNT];

	argc--;
	argv++;
	options[(ft_atoi(FLAG_L))] = (t_option){.shortc = 'l'};
	options[ft_atoi(FLAG_BR)] = (t_option){.shortc = 'R'};
	options[ft_atoi(FLAG_A)] = (t_option){.shortc = 'a'};
	options[ft_atoi(FLAG_R)] = (t_option){.shortc = 'r'};
	options[ft_atoi(FLAG_T)] = (t_option){.shortc = 't'};
	cl_init((char **)argv, options, FLAGS_COUNT);
	ls_engine();
	return (0);
}
