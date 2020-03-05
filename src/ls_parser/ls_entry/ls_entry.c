/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 23:25:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "./ls_entry.h"

t_bool		ls_parse_long_listing(void)
{
	return (TRUE);
	// size_t	counter;
	//
	// counter = 0;
	// while (counter < FDETAILS_COUNT)
	// {
	// 	if (ls_is_flag(g_flag_fdetails[counter]))
	// 		return (TRUE);
	// 	counter++;
	// }
	// return (FALSE);
}

static void	ls_entry_process(struct stat *istat, t_basic *entry)
{
	t_uint	index;
	t_uint	data_select_flags;

	data_select_flags = ls_get_group_active_flags(DATA_SELECT_GROUP);
	index = 0;
	while (index < DATA_SELECT_FLAGS_C)
	{
		if (data_select_flags & (1 << index))
			g_data_select_func[index](istat, entry, NULL);
		index++;
	}
}

static void	ls_entry(struct stat *istat, t_basic *basic)
{
	// ls_parse_name(istat, basic);
	basic->access.type = '-';
	basic->access.extra = ' ';
	ft_strcpy(basic->access.permissions, "---------");
	ls_parse_type(istat, basic);
	ls_parse_permissions(istat, basic);
	ls_entry_process(istat, basic);
	ls_parse_links(istat, basic);
	ls_parse_owner(istat, basic);
	ls_parse_size(istat, basic);
	ls_parse_date_format(istat, basic);
}

t_basic		*ls_parse_entry(char *entry, char *name)
{
	struct stat		istat;
	t_basic			*info;

	if (lstat(entry, &istat) == -1)
		perror(entry);
	info = ft_calloc(1, sizeof(t_basic));
	info->name.len = ft_pprintf(&info->name.name, "%s", name);
	info->size.size = istat.st_size;
	ls_entry(&istat, info);
	return (info);
}
