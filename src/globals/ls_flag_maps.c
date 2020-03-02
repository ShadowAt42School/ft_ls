/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:22:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 20:40:58 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_uint			g_flag_fdetails[FDETAILS_COUNT] = {
	FLAG_L
};

t_uint			g_flag_ddetails[DDETAILS_COUNT] = {
	FLAG_A
};

t_uint			g_index_to_flag[DATA_SELECTORS] = {
	FLAG_C
};

t_parse_data	g_flags_data[FLAGS_COUNT] = {
	[FLAG_C] = &ls_flag_c
};
