/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:34:39 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 19:23:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_free_list(void *content, size_t size)
{
	t_basic		*basic;

	size = 0;
	basic = (t_basic*)content;
	ft_strdel(&basic->owner.usr);
	ft_strdel(&basic->owner.grp);
	ft_strdel(&basic->size.rep);
	ft_strdel(&basic->name.name);
	ft_memdel(&content);
}


void			ls_parse_directory(char *dir, t_bool is_dir_name)
{
	t_list		*lst;
	t_paddings	pads;

	is_dir_name = FALSE;
	ft_bzero(&pads, sizeof(t_paddings));
	lst = ls_directory(dir, &pads);
	ft_lstdel(&lst, &ls_free_list);
}
