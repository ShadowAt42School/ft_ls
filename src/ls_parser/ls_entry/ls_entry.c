/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 22:52:39 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "./ls_entry.h"

t_bool	ls_parse_long_listing(void)
{
	size_t	counter;

	counter = 0;
	while (counter < FDETAILS_COUNT)
	{
		if (ls_is_flag(g_flag_fdetails[counter]))
			return (TRUE);
		counter++;
	}
	return (FALSE);
}

void	ls_entry(struct stat *istat, t_basic *basic)
{
	// ls_parse_name(istat, basic);
	basic->access.type = '-';
	basic->access.extra = ' ';
	ft_strcpy(basic->access.permissions, "---------");
	ls_parse_type(istat, basic);
	ls_parse_permissions(istat, basic);
	ls_parse_links(istat, basic);
	ls_parse_owner(istat, basic);
	ls_parse_size(istat, basic);
	if (!basic->date.time.tv_sec)
		basic->date.time = istat->st_mtimespec;
	if (!basic->date.rep)
		ls_parse_date_format(basic);
}
