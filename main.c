/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:46:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/26 00:49:09 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char const **argv)
{
	t_option	options[FLAGS_COUNT];

	argc--;
	argv++;
	options[FLAG_L] = (t_option){.shortc = 'l'};
	options[FLAG_BR] = (t_option){.shortc = 'R'};
	options[FLAG_A] = (t_option){.shortc = 'a'};
	options[FLAG_R] = (t_option){.shortc = 'r'};
	options[FLAG_T] = (t_option){.shortc = 't'};
	cl_init((char **)argv, options, FLAGS_COUNT);
	ft_printf("|%.0d|\n", 1234);
	// ls_engine();
	return (0);
}
