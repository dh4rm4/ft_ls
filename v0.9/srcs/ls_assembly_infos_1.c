/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:35 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 21:16:15 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	FILL TIME (= all->time)
**  WITH THE \\_TIME_// OF THE "FILE / DIR"
*/

static void	ls_time(int ops[11], T_STAT *infos, t_elem *all)
{
	char		*rtr;
	size_t		i;
	struct tm	*stc;

	i = -1;
	if (!OP_U)
		TIME_MEM = infos->st_mtime;
	else
		TIME_MEM = infos->st_atime;
	rtr = ft_strnew(0);
	rtr = ctime(&infos->st_atime);
	rtr += 4;
	while (ft_isdigit(*(rtr - 1)) != 1)
		TIME[++i] = *(rtr++);
	TIME[++i] = '\0';
}

/*
**	STOCK MAJOR AND MINOR FOR DEVICE
**	MAJOR = NB PERIPHERAL
**	MINOR = NB DRIVER
*/

static void	ls_device(T_STAT *infos, t_elem *all)
{
	RDEV = infos->st_rdev;
	if (RDEV)
	{
		MINOR = ft_strdup(ft_itoa(minor(infos->st_rdev)));
		MAJOR = ft_strdup(ft_itoa(major(infos->st_rdev)));
	}
}

/*
**	STOCK THE INFOS OF OPTION '-l'
*/

void		ls_infos(int ops[11], t_store *store, T_STAT *infos, t_elem *all)
{
	ls_permission(*infos, all);
	HARD_LINK = ft_itoa(infos->st_nlink);
	ls_owner(infos, all);
	ls_group(infos, all);
	SIZE = ft_itoa(infos->st_size);
	BLOCKS = infos->st_blocks;
	INODE = infos->st_ino;
	ls_device(infos, all);
	if (S_ISLNK(infos->st_mode))
	{
		readlink(PATH, DLINK, 256);
		bug(DLINK);
	}
	ls_time(ops, infos, all);
}
