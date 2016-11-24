/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:57:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 10:05:38 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	BEGINING OF THE PROG
*/
int	ls_start(const char	*path)
{
	t_dirent	*rtr_dir;
	t_elem		*all;
	t_path		*recur;

    all = malloc(sizeof(*all));
	recur = malloc(sizeof(*recur));
	AFIRST = all;
	ANEXT = NULL;
	APREV = NULL;
	RNEXT = NULL;
	RFIRST = recur;
	RPATH = NULL;
	RPREV = NULL;
	if (lstat(path, &AINFOS) == -1)
		return (ls_exit(-1));
	if (S_ISDIR(AINFOS.st_mode))
	{
		RPATH = malloc(sizeof(*RPATH) * ft_strlen(path));
		ft_strncpy(RPATH, path, ft_strlen(path));
		ls_storage(rtr_dir, all, recur);
		ls_print(rtr_dir, all, recur);
	}
//	else
//		PRISE EN CHARGE POUR UN FICHIER UNIQUE
	return (0);
}
