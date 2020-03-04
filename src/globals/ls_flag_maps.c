/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:22:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/03 23:17:31 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_uint			*g_groups[GROUPS_COUNT] = {
	[GROUP_DATA_SELECT] = g_data_select_flags,
	[GROUP_FILE_SELECT] = g_file_select_flags
};

t_uint			g_groups_counts[GROUPS_COUNT] = {
	[GROUP_DATA_SELECT] = DATA_SELECT_FLAGS_C,
	[GROUP_FILE_SELECT] = FILE_SELECT_FLAGS_C
};

t_uint			g_file_select_flags[FILE_SELECT_FLAGS_C] = {
	FLAG_A, FLAG_BA
};

t_file_func		g_file_select_func[FILE_SELECT_FLAGS_C] = {
	ls_flag_a, ls_flag_big_a
};

t_uint			g_data_select_flags[DATA_SELECT_FLAGS_C] = {
	FLAG_C
};

t_data_func		g_data_select_func[DATA_SELECT_FLAGS_C] = {
	ls_flag_c
};
