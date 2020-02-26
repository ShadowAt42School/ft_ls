/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/25 21:54:53 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_basic		*ls_parse_entry(char *entry)
{
	struct stat		istat;
	t_basic			*info;

	info = ft_calloc(1, sizeof(t_basic));
	if(stat(entry, &istat) == -1)
		perror(entry);
	info->access = istat.st_mode;
	return (info);
}
