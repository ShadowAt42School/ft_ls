/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:46:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/12 22:25:36 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char const *argv[])
{
	t_option	options[5];

	argc--;
	argv++;
	options[0] = (t_option){.shortc = 'l'};
	options[1] = (t_option){.shortc = 'R'};
	options[2] = (t_option){.shortc = 'a'};
	options[3] = (t_option){.shortc = 'r'};
	options[4] = (t_option){.shortc = 't'};
	cl_engine((char **)argv, options, argc);
	ls_engine();
	return 0;
}
