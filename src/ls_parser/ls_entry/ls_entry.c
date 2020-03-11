/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/10 23:40:44 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "./ls_entry.h"

static void	ls_entry_stat_select(char *entry, struct stat *istat)
{
	t_uint	index;
	t_uint	parse_select_flags;

	parse_select_flags = ls_get_group_active_flags(STAT_SELECT_GROUP);
	index = 0;
	while (index < STAT_SELECT_FLAGS_C)
	{
		if (parse_select_flags & (1 << index))
		{
			g_stat_select_func[index](entry, istat);
			return ;
		}
		index++;
	}
	if (lstat(entry, istat) == -1)
		perror(entry);
}

static void	ls_entry_data_select(struct stat *istat, t_basic *entry)
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
	basic->access.type = '-';
	basic->access.extra = ' ';
	ft_strcpy(basic->access.permissions, "---------");
	ls_parse_type(istat, basic);
	ls_parse_permissions(istat, basic);
	ls_entry_data_select(istat, basic);
	ls_parse_links(istat, basic);
	ls_parse_owner(istat, basic);
	ls_parse_size(istat, basic);
	ls_parse_date_format(istat, basic);
	ls_parse_name(istat, basic);
}

t_basic		*ls_parse_entry(char *entry, char *name)
{
	struct stat		istat;
	t_basic			*info;

	ft_bzero(&istat, sizeof(istat));
	ls_entry_stat_select(entry, &istat);
	info = ft_calloc(1, sizeof(t_basic));
	info->path = entry;
	info->name.len = ft_pprintf(&info->name.name, "%s", name);
	info->name.pname.should_set = TRUE;
	ls_entry(&istat, info);
	return (info);
}
