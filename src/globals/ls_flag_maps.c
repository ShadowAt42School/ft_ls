/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:22:31 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/06 19:47:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_uint			*g_groups[GROUPS_COUNT] = {
	[DATA_SELECT_GROUP] = g_data_select_flags,
	[FILE_SELECT_GROUP] = g_file_select_flags,
	[SORT_SELECT_GROUP] = g_sort_select_flags,
	[PRINT_SELECT_GROUP] = g_print_select_flags,
};

t_uint			g_groups_counts[GROUPS_COUNT] = {
	[DATA_SELECT_GROUP] = DATA_SELECT_FLAGS_C,
	[FILE_SELECT_GROUP] = FILE_SELECT_FLAGS_C,
	[SORT_SELECT_GROUP] = SORT_SELECT_FLAGS_C,
	[PRINT_SELECT_GROUP] = PRINT_SELECT_FLAGS_C,
};

/*
**	File select group
*/
t_uint			g_file_select_flags[FILE_SELECT_FLAGS_C] = {
	FLAG_A, FLAG_BA
};

t_file_func		g_file_select_func[FILE_SELECT_FLAGS_C] = {
	ls_flag_a, ls_flag_big_a
};

/*
**	Data select group
*/
t_uint			g_data_select_flags[DATA_SELECT_FLAGS_C] = {
	FLAG_C
};

t_data_func		g_data_select_func[DATA_SELECT_FLAGS_C] = {
	ls_flag_c
};

/*
**	Sorting group
*/
t_uint			g_sort_select_flags[SORT_SELECT_FLAGS_C] = {
	FLAG_T
};

t_sort_func		g_sort_select_func[SORT_SELECT_FLAGS_C] = {
	ls_flag_t
};

/*
**	Item representation group
*/
t_uint			g_print_select_flags[SORT_SELECT_FLAGS_C] = {
	FLAG_L
};

t_print_func	g_print_select_func[SORT_SELECT_FLAGS_C] = {
	ls_flag_l
};
