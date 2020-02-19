/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/18 21:07:33 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <dirent.h>
# include "ft_stdio.h"

# define FLAGS_STR	"lRrta"
# define FLAG_L		1
# define FLAG_BR	2
# define FLAG_R		4
# define FLAG_T 	8
# define FLAG_A 	16

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
**	Flags
*/

void	ls_flags_parse();
t_bool	ls_is_flag(t_uint flag);

#endif
