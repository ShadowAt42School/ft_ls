/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:03:19 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/04 22:37:06 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_entry.h"

static void		permission_parse_sticky(struct stat *istat, t_basic *basic)
{
	t_bool	is_set_user_id;
	t_bool	is_set_group_id;
	t_bool	is_sticky;
	t_bool	is_exec[3];

	is_set_user_id = (S_ISUID & istat->st_mode ? TRUE : FALSE);
	is_set_group_id = (S_ISGID & istat->st_mode ? TRUE : FALSE);
	is_sticky = (S_ISVTX & istat->st_mode ? TRUE : FALSE);
	is_exec[0] = basic->access.permissions[2];
	is_exec[1] = basic->access.permissions[5];
	is_exec[2] = basic->access.permissions[8];
	if (is_set_user_id && is_sticky)
		basic->access.permissions[2] = is_exec[0] == 'x' ? 's' : 'S';
	if (is_set_group_id && is_sticky)
		basic->access.permissions[5] = is_exec[1] == 'x' ? 's' : 'S';
	if (is_set_user_id && is_sticky)
		basic->access.permissions[8] = is_exec[2] == 'x' ? 't' : 'T';
}

void			ls_parse_type(struct stat *istat, t_basic *basic)
{
	if (S_ISREG(istat->st_mode))
		basic->access.type = T_ACCESS_FILE;
	else if (S_ISDIR(istat->st_mode))
		basic->access.type = T_ACCESS_DIR;
	else if (S_ISCHR(istat->st_mode))
		basic->access.type = T_ACCESS_CHR;
	else if (S_ISBLK(istat->st_mode))
		basic->access.type = T_ACCESS_BLK;
	else if (S_ISFIFO(istat->st_mode))
		basic->access.type = T_ACCESS_FIFO;
	else if (S_ISLNK(istat->st_mode))
		basic->access.type = T_ACCESS_LINK;
	else if (S_ISSOCK(istat->st_mode))
		basic->access.type = T_ACCESS_SOC;
}

void			ls_parse_permissions(struct stat *istat, t_basic *basic)
{
	if (S_IRUSR & istat->st_mode)
		basic->access.permissions[0] = 'r';
	if (S_IWUSR & istat->st_mode)
		basic->access.permissions[1] = 'w';
	if (S_IXUSR & istat->st_mode)
		basic->access.permissions[2] = 'x';
	if (S_IRGRP & istat->st_mode)
		basic->access.permissions[3] = 'r';
	if (S_IWGRP & istat->st_mode)
		basic->access.permissions[4] = 'w';
	if (S_IXGRP & istat->st_mode)
		basic->access.permissions[5] = 'x';
	if (S_IROTH & istat->st_mode)
		basic->access.permissions[6] = 'r';
	if (S_IWOTH & istat->st_mode)
		basic->access.permissions[7] = 'w';
	if (S_IXOTH & istat->st_mode)
		basic->access.permissions[8] = 'x';
	permission_parse_sticky(istat, basic);
}
