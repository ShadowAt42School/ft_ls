/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 22:52:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_parse_directory(char *dir)
{
	t_list				*lst;

	lst = ls_directory(dir);
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
	ls_entry_process(&istat, info);
	ls_entry(&istat, info);
	return (info);
}
