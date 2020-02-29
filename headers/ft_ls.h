/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 04:10:09 by maghayev         ###   ########.fr       */
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
# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_stdio.h"

# define FLAGS_COUNT			5
# define FLAGS_STR				"lRrta"
# define DIR_PROCESS_OPTS_MAP	"4"
# define FLAG_L					"0"
# define FLAG_BR				"1"
# define FLAG_R					"2"
# define FLAG_T 				"3"
# define FLAG_A 				"4"

# define FDETAILS_COUNT			1
extern char			*g_flag_fdetails[FDETAILS_COUNT];

# define DDETAILS_COUNT			1
extern char			*g_flag_ddetails[DDETAILS_COUNT];

typedef struct	s_paddings {
	size_t			links;
	size_t			usr;
	size_t			grp;
	size_t			size;
}				t_paddings;

typedef struct	s_dir {
	DIR				*stream;
	struct dirent	*ent;
	t_uint			len;
}				t_dir;

typedef struct	s_access {
	char			type;
	char			permissions[9];
}				t_access;

typedef struct	s_links {
	char			*links;
	size_t			linksl;
}				t_links;

typedef struct	s_ownership {
	uid_t			st_uid;
	gid_t			st_gid;
	char			*usr;
	char			*grp;
	size_t			usrl;
	size_t			grpl;
}				t_ownership;

typedef struct	s_size {
	char			*size;
	size_t			sizel;
}				t_size;

typedef struct	s_date {
	struct timespec	time;
	char			*date;
}				t_date;

typedef struct	s_name {
	char			*name;
	char			marking;
	unsigned int	len;
}				t_name;

typedef struct	s_basic {
	t_access		access;
	t_links			links;
	t_ownership		owner;
	t_size			size;
	t_date			date;
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
**	Entry parsers
*/
void			ls_parse_name(struct stat *stat, t_basic *basic);
t_bool			ls_parse_long_listing();
void			ls_parse_owner(struct stat *istat, t_basic *basic);
void			ls_parse_access(struct stat *istat, t_basic *basic);
void			ls_parse_type(struct stat *istat, t_basic *basic);
void			ls_parse_permissions(struct stat *istat, t_basic *basic);
void			ls_parse_size(struct stat *istat, t_basic *basic);
void			ls_parse_date(struct stat *stat, t_basic *basic);

/*
**	Flags
*/
void			ls_flags_parse();
t_bool			ls_is_flag(char *flag);
t_bool			ls_process_a(struct dirent *ent);

/*
**	Print
*/
void			ls_print(t_list *lst);

#endif
