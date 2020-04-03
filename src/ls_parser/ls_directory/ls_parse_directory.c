/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:48:51 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/27 17:46:30 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ls_directory.h"

static char		**ls_recursive_process(t_list *lst)
{
	t_list	*run;
	size_t	count;
	char	**directories;
	size_t	index;

	count = 0;
	index = 0;
	run = lst;
	while (run)
	{
		if (((t_basic *)run->content)->access.type == T_ACCESS_DIR)
			count++;
		run = run->next;
	}
	run = lst;
	directories = (char**)ft_calloc(count + 1, sizeof(char*));
	while (run)
	{
		if (((t_basic *)run->content)->access.type == T_ACCESS_DIR)
		{
			directories[index] =
								ft_strdup(((t_basic *)run->content)->name.name);
			index++;
		}
		run = run->next;
	}
	return (directories);
}

void			ls_free_list(void *content, size_t size)
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

void			ls_parse_directory(char *dir,
	t_bool is_dir_name,
	char ***directories)
{
	t_list		*lst;
	t_paddings	pads;

	is_dir_name = FALSE;
	ft_bzero(&pads, sizeof(t_paddings));
	lst = ls_directory(dir, &pads);
	if (directories)
		*directories = ls_recursive_process(lst);
	ft_lstdel(&lst, &ls_free_list);
}
