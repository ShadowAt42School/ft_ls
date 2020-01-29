/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/01/06 21:47:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libs/ft_stdio/headers/ft_stdio.h"

typedef struct		s_flags {
	t_bool			is_l;
	t_bool			is_br;
	t_bool			is_r;
	t_bool			is_t;
}					t_flags;

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

#endif
