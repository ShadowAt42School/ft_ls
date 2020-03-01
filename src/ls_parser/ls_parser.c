/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 00:31:24 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_pars_dir_paddings(t_basic *info, t_paddings *pads)
{
	pads->links = ft_umax(info->links.linksl, pads->links);
	pads->usr = ft_umax(info->owner.usrl, pads->usr);
	pads->grp = ft_umax(info->owner.grpl, pads->grp);
	pads->size = ft_umax(info->size.sizel, pads->size);
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
	ls_print(lst, &pads);
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
	ls_parse_defaults(&istat, info);
	return (info);
}
