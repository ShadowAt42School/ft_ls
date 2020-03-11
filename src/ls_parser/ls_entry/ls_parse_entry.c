/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/10 21:23:46 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "./ls_entry.h"

void	ls_parse_links(struct stat *istat, t_basic *basic)
{
	if (basic->links.linksl != 0)
		return ;
	basic->links.links = istat->st_nlink;
	basic->links.linksl = ft_numlen(&basic->links.links, FALSE);
}

void	ls_parse_owner(struct stat *istat, t_basic *basic)
{
	struct passwd	*st_uid;
	struct group	*st_gid;

	if (!basic->owner.usr_set)
	{
		st_uid = getpwuid(istat->st_uid);
		if (!st_uid)
			basic->owner.usrl = ft_pprintf(&basic->owner.usr,
				"%lu", istat->st_uid);
		else
			basic->owner.usrl = ft_pprintf(&basic->owner.usr,
				"%s", st_uid->pw_name);
	}
	if (!basic->owner.grp_set)
	{
		st_gid = getgrgid(istat->st_gid);
		if (!st_gid)
			basic->owner.grpl = ft_pprintf(&basic->owner.grp,
				"%lu", istat->st_gid);
		else
			basic->owner.grpl = ft_pprintf(&basic->owner.grp,
				"%s", st_gid->gr_name);
	}
}

void	ls_parse_size(struct stat *istat, t_basic *basic)
{
	basic->size.blks = istat->st_blocks;
	if (!basic->size.size)
		basic->size.size = istat->st_size;
	if (basic->size.rep)
		return ;
	basic->size.sizel = ft_pprintf(&basic->size.rep, "%ld", istat->st_size);
}

void	ls_parse_date_format(struct stat *istat, t_basic *basic)
{
	char	*datetime;
	t_bool	is_year;

	if (!basic->date.time.tv_sec)
		basic->date.time = istat->st_mtimespec;
	if (!basic->date.rep[0])
	{
		datetime = ctime(&basic->date.time.tv_sec);
		is_year = time(NULL) - basic->date.time.tv_sec > 15552000;
		ft_sprintf(basic->date.rep,
			DEFAULT_DATE_FORMAT,
			(datetime + 4),
			(datetime + 8),
			is_year ? 4 : 5,
			is_year ? (datetime + 20) : (datetime + 11));
	}
}

void	ls_parse_name(struct stat *istat, t_basic *basic)
{
	if (S_ISLNK(istat->st_mode))
	{
		if (basic->name.pname.should_set && basic->name.pname.len == 0)
		{
			basic->name.pname.len = istat->st_size + 4;
			ft_memcpy(basic->name.pname.name, " -> ", 4);
			readlink(basic->path, basic->name.pname.name + 4, istat->st_size);
		}
	}
}
