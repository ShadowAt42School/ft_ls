/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:28:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 20:24:56 by maghayev         ###   ########.fr       */
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

/*
**	Global defines
*/
# define T_ACCESS_FILE	'-'
# define T_ACCESS_DIR	'd'
# define T_ACCESS_CHR	'c'
# define T_ACCESS_BLK	'b'
# define T_ACCESS_FIFO	'p'
# define T_ACCESS_LINK	'l'
# define T_ACCESS_SOC	's'

typedef struct	s_paddings {
	size_t			links;
	size_t			usr;
	size_t			grp;
	size_t			size;
	size_t			count;
	size_t			total_blocks;
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
	t_uint			major;
	t_uint			minor;
	off_t			size;
	blkcnt_t		blks;
	size_t			sizel;
	t_bool			is_spec;
	char			*rep;
}				t_size;

typedef struct	s_date {
	struct timespec	time;
	char			rep[25];
}				t_date;

typedef struct	s_pname {
	char			name[PATH_MAX + 1];
	size_t			len;
	t_bool			should_set;
}				t_pname;

typedef struct	s_name {
	char			*name;
	t_pname			pname;
	char			marking;
	unsigned int	len;
}				t_name;

typedef struct	s_basic {
	char			*path;
	t_access		access;
	t_links			links;
	t_ownership		owner;
	t_size			size;
	t_date			date;
	t_name			name;
}				t_basic;

# define DEFAULT_DATE_FORMAT	"%.3s %.2s %5.*s"
# define LONG_DATE_FORMAT		"%.3s .3s %.2s %8s %4s"

# define FLAGS_COUNT			9
# define FLAGS_STR				"lRrtaAcFH"
# define FLAG_L					0
# define FLAG_BR				1
# define FLAG_R					2
# define FLAG_T 				3
# define FLAG_A 				4
# define FLAG_BA 				5
# define FLAG_C 				6
# define FLAG_BF 				7
# define FLAG_BH 				8

# define GROUPS_COUNT			5

extern t_uint		*g_groups[GROUPS_COUNT];
extern t_uint		g_groups_counts[GROUPS_COUNT];

# define FILE_SELECT_GROUP		0
# define FILE_SELECT_FLAGS_C	2

extern t_uint		g_file_select_flags[FILE_SELECT_FLAGS_C];
typedef void	(*t_file_func)(struct dirent *, void *);
extern t_file_func	g_file_select_func[FILE_SELECT_FLAGS_C];

# define STAT_SELECT_GROUP		1
# define STAT_SELECT_FLAGS_C	0

extern t_uint		g_stat_select_flags[STAT_SELECT_FLAGS_C];
typedef void	(*t_stat_func)(char *, struct stat *);
extern t_stat_func	g_stat_select_func[STAT_SELECT_FLAGS_C];

# define DATA_SELECT_GROUP		2
# define DATA_SELECT_FLAGS_C	2

extern t_uint		g_data_select_flags[DATA_SELECT_FLAGS_C];
typedef void	(*t_data_func)(struct stat *, t_basic *, void *);
extern t_data_func	g_data_select_func[DATA_SELECT_FLAGS_C];

# define SORT_SELECT_GROUP		3
# define SORT_SELECT_FLAGS_C	1

extern t_uint		g_sort_select_flags[SORT_SELECT_FLAGS_C];
typedef void	(*t_sort_func)(t_list *lst, t_bool reverse);
extern t_sort_func	g_sort_select_func[SORT_SELECT_FLAGS_C];

# define PRINT_SELECT_GROUP		4
# define PRINT_SELECT_FLAGS_C	1

extern t_uint		g_print_select_flags[PRINT_SELECT_FLAGS_C];
typedef void	(*t_print_func)(t_list *lst, t_paddings *pads);
extern t_print_func	g_print_select_func[PRINT_SELECT_FLAGS_C];

/*
**	Engine
*/
void			ls_engine();

/*
**	Error
*/
char			*ls_error(char *prefix);

/*
**	Parser Engine
*/
void			ls_parse_directory(char *dir, t_bool is_dir_name, char ***dirs);
t_basic			*ls_parse_dir_file(
							char *dir, struct dirent *ent, t_paddings *pads);
t_basic			*ls_parse_entry(char *entry, char *display_name);

/*
**	Entry parsers
*/
void			ls_parse_name(struct stat *stat, t_basic *basic);
t_bool			ls_parse_long_listing();

/*
**	Flags
*/
void			ls_flags_parse();
t_bool			ls_is_flag(t_uint flag);
t_uint			ls_get_group_active_flags(t_uint group_id);

/*
**	HERE
*/
void			ls_flag_big_r(char *path);
void			ls_flag_a(struct dirent *ent, void *res);
void			ls_flag_big_a(struct dirent *ent, void *res);
void			ls_flag_c(struct stat *istat, t_basic *basic, void *res);
void			ls_flag_big_f(struct stat *istat, t_basic *basic, void *res);
void			ls_flag_t(t_list *lst, t_bool reverse);
void			ls_flag_l(t_list *lst, t_paddings *pads);

#endif
