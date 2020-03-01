/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_processors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:38:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 21:28:26 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool	ls_dir_processing(struct dirent *ent)
{
	t_bool		final;
	char		flag;
	char		*options;

	options = "4";
	final = FALSE;
	while ((flag = ft_atoi(options)))
	{
		final = ls_process_a(ent);
		options++;
	}
	return (final);
}

void	ls_entry_process(struct stat *istat, t_basic *entry)
{
	t_uint	index;

	index = 0;
	while(index < DATA_SELECTORS)
	{
		if (ls_is_flag(g_index_to_flag[index]))
			g_flags_data[g_index_to_flag[index]](istat, entry);
		index++;
	}
}
