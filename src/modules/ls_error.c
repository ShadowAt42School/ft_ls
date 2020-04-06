/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:54 by maghayev          #+#    #+#             */
/*   Updated: 2020/04/05 20:24:33 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_ls.h"

char	*ls_error(char *prefix)
{
	char	*error_string;

	error_string = NULL;
	ft_pprintf(&error_string, "ft_ls: %s: %s", prefix, strerror(errno));
	return (error_string);
}
