/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:28:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:56:40 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	RETURN NBR OPTION PASSED IN ARG
*/

static int	ls_nb_options(int ops[11])
{
	int	rtr;

	rtr = OP_L;
	rtr += OP_R;
	rtr += OP_A;
	rtr += OP_RR;
	rtr += OP_T;
	rtr += OP_AA;
	rtr += OP_D;
	return (rtr);
}

/*
**	SOR ARGS FOR EXEPLE BELLOW :
**	./ft_ls -r [FILE_0] [FILE_1] [FILE_2] [DIRECTORY]
*/

static void	ls_reverse_files_arg(int ops[11], char *av[])
{
	int		x;
	int		y;
	char	*tmp;
	T_STAT	stat;

	x = ls_nb_options(ops);
	y = x + 1;
	while (av[y] && lstat(av[y], &stat) == 0)
		if (!S_ISDIR(stat.st_mode))
			++y;
	while (++x < --y)
	{
		tmp = av[x];
		av[x] = av[y];
		av[y] = tmp;
	}
}

/*
**	SORT ARG :
**	1. FILE
**	2. DIRECTORY
*/

static void	ls_arg_sort(int ops[11], int ac, char *av[])
{
	char	*tmp;
	T_STAT	cur_stat;
	T_STAT	nxt_stat;
	int		i;

	i = 1;
	while (i + 1 < ac)
	{
		lstat(av[i], &cur_stat);
		lstat(av[i + 1], &nxt_stat);
		if (S_ISDIR(cur_stat.st_mode) && !S_ISDIR(nxt_stat.st_mode))
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
		}
		++i;
	}
	if (OP_RR)
		ls_reverse_files_arg(ops, av);
}

/*
**  MANAGE FILE/DIRECTORY NAME PAST IN ARGUMENT
*/

void		ls_arg(int ops[11], int ac, char *av[], t_elem *all)
{
	int		x;
	T_STAT	stat;

	x = 1;
	if (av[1] && av[1][0] == '-')
		while (av[x] && av[x][0] == '-')
			++x;
	ls_arg_sort(ops, ac, av);
	while (av[x])
	{
		lstat(av[x], &stat);
		if (x != 1 && !OP_D && S_ISDIR(stat.st_mode) && \
			ft_strcmp(".", av[x]) && ft_strcmp("..", av[x]))
			ft_printf("%s:\n", av[x]);
		ls_start(ops, av[x++], all);
		if (!OP_D && av[x])
		{
			lstat(av[x], &stat);
			if (S_ISDIR(stat.st_mode))
				ft_putchar('\n');
		}
	}
	if ((av[x - 1] && av[x - 1][0] == '-') || x - 1 == 0)
		ls_start(ops, ".", all);
}
