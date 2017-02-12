/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:28:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/20 14:20:56 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	SOR ARGS FOR EXEPLE BELLOW :
**	./ft_ls -r [FILE_0] [FILE_1] [FILE_2] [DIRECTORY]
*/

static void	ls_reverse_files_arg(int ops[11], int ac, char *av[])
{
	t_xy	co;
	int		z;
	char	*tmp;
	T_STAT	stat;

	co.x = ls_nb_options(ops);
	co.y = co.x + 1;
	while (av[co.y] && lstat(av[co.y], &stat) == 0 && !S_ISDIR(stat.st_mode))
		++co.y;
	z = co.y;
	while (co.x < --co.y)
	{
		tmp = av[co.x];
		av[co.x++] = av[co.y];
		av[co.y] = tmp;
	}
	while (z < --ac)
	{
		tmp = av[z];
		av[z++] = av[ac];
		av[ac] = tmp;
	}
}

/*
**	SORT ARG WITH ALPHA
*/

static int	ls_alag(int i, int dir, char *av[])
{
	T_STAT	cur_stat;
	T_STAT	nxt_stat;
	char	*tmp;

	while (av[i + 1])
	{
		lstat(av[i], &cur_stat);
		lstat(av[i + 1], &nxt_stat);
		if (!dir && (S_ISDIR(cur_stat.st_mode) || S_ISDIR(nxt_stat.st_mode)))
			return (ls_alag((S_ISDIR(cur_stat.st_mode) ? i : ++i), 1, av));
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = 0;
		}
		++i;
	}
	return (0);
}

static void	ls_arg_sort_loop(t_xy *co, char *tmp, int *rtr, char *av[])
{
	T_STAT	cur_stat;
	T_STAT	nxt_stat;

	lstat(av[co->x], &cur_stat);
	if (S_ISDIR(cur_stat.st_mode))
	{
		co->y = co->x + 1;
		while (av[co->y] && lstat(av[co->y], &nxt_stat) == 0
			&& S_ISDIR(nxt_stat.st_mode))
			++co->y;
		if (av[co->y] && !S_ISDIR(nxt_stat.st_mode))
		{
			tmp = av[co->x];
			av[co->x] = av[co->y];
			av[co->y] = tmp;
		}
	}
	if (av[co->x][0] != '-')
		++(*rtr);
	++co->x;
}

/*
**	SORT ARG :
**	1. FILE
**	2. DIRECTORY
*/

static int	ls_arg_sort(int ops[11], int ac, char *av[])
{
	char	*tmp;
	t_xy	co;
	int		rtr;

	co.x = 1;
	rtr = 0;
	while (co.x + 1 < ac)
		ls_arg_sort_loop(&co, tmp, &rtr, av);
	if (av[co.x][0] != '-')
		++rtr;
	ls_alag(1, 0, av);
	if (OP_RR)
		ls_reverse_files_arg(ops, ac, av);
	return (rtr);
}

/*
**  MANAGE FILE/DIRECTORY NAME PAST IN ARGUMENT
*/

void		ls_arg(int ops[11], int ac, char *av[], t_elem *all)
{
	int		x;
	T_STAT	stat;
	int		nb_ag;

	x = 1;
	while (av[x] && cmpc(av[x][0], '-'))
		++x;
	if (ac > 1)
		nb_ag = ls_arg_sort(ops, ac, av);
	while (av[x])
	{
		lstat(av[x], &stat);
		if ((x != 1 || nb_ag > 1) && !OP_D && S_ISDIR(stat.st_mode) &&
			ft_strcmp(".", av[x]) && ft_strcmp("..", av[x]) && nb_ag > 1)
			ft_printf("%s:\n", av[x]);
		if (ac > 1)
			ls_start(ops, av[x++], all);
		else
			ls_start(ops, ".", all);
		if (!OP_D && av[x])
			if (lstat(av[x], &stat) == 0 && S_ISDIR(stat.st_mode))
				ft_putchar('\n');
	}
	if ((av[x - 1] && cmpc(av[x - 1][0], '-')) || x - 1 == 0)
		ls_start(ops, ".", all);
}
