/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:46:38 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/04 22:28:04 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/ft_stdio/ft_stdio.h"

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
	return 0;
}