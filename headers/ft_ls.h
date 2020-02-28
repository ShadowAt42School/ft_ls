/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/28 00:16:05 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_stdio.h"

# define FLAGS_COUNT			5
# define FLAGS_STR				"lRrta"
# define DIR_PROCESS_OPTS_MAP	"4"
# define FLAG_L					0
# define FLAG_BR				1
# define FLAG_R					2
# define FLAG_T 				3
# define FLAG_A 				4

typedef struct	s_access {
	char			type;
	char			permissions[9];
}				t_access;

typedef struct	s_ownership {
	char			*usr;
	char			*grp;
	size_t			usrl;
	size_t			grpl;
	size_t			musrl;
	size_t			mgrpl;
}				t_ownership;

typedef struct	s_size {
	off_t			size;
	char			*sizes;
	size_t			sizel;
}				t_size;

typedef struct	s_name {
	char			*name;
	char			marking;
	unsigned int	len;
}				t_name;

typedef struct	s_basic {
	t_access		access;
	nlink_t			links;
	t_ownership		owner;
	t_size			size;
	char			*date_created;
	t_name			name;
}				t_basic;

/*
**	Engine
*/
void			ls_engine();

/*
**	Processors
*/
t_bool			ls_dir_processing(struct dirent *ent);

/*
**	Parser Engine
*/
void			ls_parse_directory(char *dir);
t_basic			*ls_parse_entry(char *entry, char *display_name);

/*
**	Parsers
*/
void			ls_parse_owner(struct stat *istat, t_basic *basic,
																t_bool is_id);
void			ls_parse_access(struct stat *istat, t_basic *basic);

/*
**	Entry parsers
*/
void 			ls_parse_type(struct stat *istat, t_basic *basic);
void			ls_parse_permissions(struct stat *istat, t_basic *basic);
void			ls_parse_size(struct stat *istat, t_basic *basic);

/*
**	Flags
*/
void			ls_flags_parse();
t_bool			ls_is_flag(t_uint flag);
t_bool			ls_process_a(struct dirent *ent);

#endif
