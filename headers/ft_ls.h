/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 22:50:20 by maghayev         ###   ########.fr       */
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
	size_t			total_blocks;
}				t_dir;

typedef struct	s_access {
	char			type;
	char			extra;
	char			permissions[10];
}				t_access;

typedef struct	s_links {
	nlink_t			links;
	size_t			linksl;
}				t_links;

typedef struct	s_ownership {
	t_bool			usr_set;
	t_bool			grp_set;
	char			*usr;
	char			*grp;
	size_t			usrl;
	size_t			grpl;
}				t_ownership;

typedef struct	s_size {
	off_t			size;
	char			*rep;
	size_t			sizel;
}				t_size;

typedef struct	s_date {
	struct timespec	time;
	char			*rep;
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

# define FLAGS_COUNT			6
# define FLAGS_STR				"lRrtac"
# define FLAG_L					0
# define FLAG_BR				1
# define FLAG_R					2
# define FLAG_T 				3
# define FLAG_A 				4
# define FLAG_C 				5

# define FDETAILS_COUNT			1

extern t_uint		g_flag_fdetails[FDETAILS_COUNT];

# define DDETAILS_COUNT			1

extern t_uint		g_flag_ddetails[DDETAILS_COUNT];

# define DATA_SELECTORS			1

extern t_uint		g_index_to_flag[DATA_SELECTORS];

# define DATA_PARSE_FLAGS_COUNT	1

typedef void	(*t_parse_data)(struct stat *, t_basic *);
extern t_parse_data	g_flags_data[FLAGS_COUNT];

/*
**	Engine
*/
void			ls_engine();

/*
**	Processors
*/
t_bool			ls_dir_processing(struct dirent *ent);
void			ls_entry_process(struct stat *istat, t_basic *entry);

/*
**	Parser Engine
*/
void			ls_parse_directory(char *dir);
t_basic			*ls_parse_entry(char *entry, char *display_name);
t_list			*ls_directory(char *dir);

/*
**	Entry parsers
*/
void			ls_entry(struct stat *istat, t_basic *basic);
void			ls_parse_name(struct stat *stat, t_basic *basic);
t_bool			ls_parse_long_listing();

/*
**	Flags
*/
void			ls_flags_parse();
t_bool			ls_is_flag(t_uint flag);

/*
**	HERE
*/
t_bool			ls_process_a(struct dirent *ent);
void			ls_flag_c(struct stat *istat, t_basic *basic);
void			ls_flag_big_f(struct stat *istat, t_basic *basic);

/*
**	Print
*/
void			ls_print(t_list *lst, t_paddings *pads);

#endif
