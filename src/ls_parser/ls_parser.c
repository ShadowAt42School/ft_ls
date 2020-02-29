/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 04:17:36 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_pars_dir_paddings(t_basic *info, t_paddings *pads)
{
	if (pads->links < info->links.linksl)
		pads->links = info->links.linksl;
	if (pads->usr < info->owner.usrl)
		pads->usr = info->owner.usrl;
	if (pads->grp < info->owner.grpl)
		pads->grp = info->owner.grpl;
	if (pads->size < info->size.sizel)
		pads->size = info->size.sizel;
}

void		ls_parse_directory(char *dir)
{
	t_dir				curd;
	t_basic				*entry;
	t_list				*lst;
	static t_paddings	pads;

	curd.stream = opendir(dir);
	curd.len = ft_strlen(dir);
	lst = NULL;
	ft_strlcpy(dir + curd.len++, "/", 1);
	while ((curd.ent = readdir(curd.stream)))
	{
		ft_strlcpy(dir + curd.len, curd.ent->d_name, PATH_MAX);
		entry = ls_parse_entry(dir, curd.ent->d_name);
		if (entry == NULL)
			continue ;
		ls_pars_dir_paddings(entry, &pads);
		ft_lstadd(&lst, ft_lstnewp(entry, sizeof(entry)));
	}
	closedir(curd.stream);
	ft_bzero(dir + curd.len - 1, PATH_MAX - curd.len - 1);
	ls_print(lst);
}

t_basic		*ls_parse_entry(char *entry, char *name)
{
	struct stat		istat;
	t_basic			*info;

	if (lstat(entry, &istat) == -1)
		perror(entry);
	info = ft_calloc(1, sizeof(t_basic));
	info->name.len = ft_pprintf(&info->name.name, "%s", name);
	ls_parse_name(&istat, info);
	ls_parse_access(&istat, info);
	info->links.linksl = ft_pprintf(
								&info->links.links, "%lu", istat.st_nlink);
	info->size.sizel = ft_pprintf(&info->size.size, "%lu", istat.st_size);
	info->owner.st_uid = istat.st_uid;
	info->owner.st_gid = istat.st_gid;
	info->date.time = istat.st_mtimespec;
	return (info);
}
