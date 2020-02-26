/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/23 01:49:20 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_stdio.h"

# define FLAGS_COUNT	5
# define FLAGS_STR		"lRrta"
# define FLAG_L			0
# define FLAG_BR		1
# define FLAG_R			2
# define FLAG_T 		3
# define FLAG_A 		4

typedef struct		s_name {
	char			*name;
	unsigned int	len;
}					t_name;

typedef struct		s_ownership {
	char			*owner;
	char			*group;
	int				user_id;
	int				group_id;
}					t_ownership;

typedef struct		s_basic {
	t_name			name;
	t_ownership		owner;
	char			*date_created;
	size_t			access;
}					t_basic;

void	ls_engine();

/*
**	Parsers
*/
void	ls_parse_directory(char *dir);
t_basic	*ls_parse_entry(char *entry);

/*
**	Flags
*/

void	ls_flags_parse();
t_bool	ls_is_flag(t_uint flag);

#endif
