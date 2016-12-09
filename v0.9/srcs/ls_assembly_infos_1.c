/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:35 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:57:32 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	GIVE VALUE OF HOUR TO all->hour_year
*/

static void	ls_time_year(char *str, t_elem *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[++i])
		;
	i -= 5;
	while (str[i + 1])
	{
		H_Y[j++] = str[i];
		++i;
	}
	H_Y[j] = '\0';
}

/*
**	GIVE VALUE OF HOUR TO all->hour_year
*/

static void	ls_time_hour(char *str, t_elem *all)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	++str;
	while (check < 2)
	{
		H_Y[i++] = *str;
		if (*(str + 1) == ':')
			++check;
		++str;
	}
	H_Y[i] = '\0';
}

/*
**  FILL TIME (= all->time)
**  WITH THE \\_TIME_// OF THE "FILE / DIR"
*/

static void	ls_time(int ops[11], T_STAT *infos, t_elem *all)
{
	char	*rtr;
	size_t	i;
	time_t	stc;

	i = -1;
	if (!OP_U)
		TIME_MEM = infos->st_mtime;
	else
		TIME_MEM = infos->st_atime;
	rtr = ft_strnew(0);
	rtr = ctime(&TIME_MEM);
	rtr += 4;
	while (ft_isdigit(*(rtr - 2)) != 1)
		TIME[++i] = *(rtr++);
	TIME[++i] = '\0';
	stc = time(NULL);
	if (stc - TIME_MEM >= 15811200)
		ls_time_year(rtr, all);
	else
		ls_time_hour(rtr, all);
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
	else
	{
		MINOR = NULL;
		MAJOR = NULL;
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
		readlink(PATH, DLINK, 256);
	ls_time(ops, infos, all);
}
