/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:58 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/28 00:32:43 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parse_owner(struct stat *istat, t_basic *basic, t_bool is_id)
{
	struct group	*guis;
	struct passwd	*uids;

	if (is_id)
	{
		basic->owner.grpl = ft_sprintf(basic->owner.grp, "%u", istat->st_gid);
		basic->owner.usrl = ft_sprintf(basic->owner.usr, "%u", istat->st_gid);
		return ;
	} else {
		if ((guis = getgrgid(istat->st_gid)))
			basic->owner.grpl = ft_pprintf(
										&basic->owner.grp, "%s", guis->gr_name);
		else
			basic->owner.grpl = ft_sprintf(
										basic->owner.grp, "%u", istat->st_gid);
		if ((uids = getpwuid(istat->st_uid)))
			basic->owner.usrl = ft_pprintf(
										&basic->owner.usr, "%s", uids->pw_name);
		else
			basic->owner.usrl = ft_sprintf(
										basic->owner.usr, "%u", istat->st_gid);
	}
	if (basic->owner.musrl < basic->owner.usrl)
		basic->owner.musrl = basic->owner.usrl;
	if (basic->owner.mgrpl < basic->owner.grpl)
		basic->owner.mgrpl = basic->owner.grpl;
}

void	ls_parse_access(struct stat *istat, t_basic *basic)
{
	ft_strcpy(basic->access.permissions, "---------");
	basic->access.type = '-';
	ls_parse_type(istat, basic);
	ls_parse_permissions(istat, basic);
}

void	ls_parse_size(struct stat *istat, t_basic *basic)
{
	basic->size.size = istat->st_size;
	basic->size.sizel = ft_sprintf(basic->size.sizes, "%lu", istat->st_size);
}

void	ls_parse_name(t_basic *basic)
{
}
