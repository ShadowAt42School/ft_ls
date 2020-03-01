/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:18:46 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 23:27:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ENTRY_H
# define LS_ENTRY_H
#include "ft_ls.h"

void			ls_parse_type(struct stat *istat, t_basic *basic);
void			ls_parse_permissions(struct stat *istat, t_basic *basic);
void			ls_parse_links(struct stat *istat, t_basic *basic);
void			ls_parse_owner(struct stat *istat, t_basic *basic);
void			ls_parse_size(struct stat *istat, t_basic *basic);
void			ls_parse_date_format(t_basic *basic);

#endif
