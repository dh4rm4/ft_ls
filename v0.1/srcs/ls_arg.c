/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:28:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 09:04:57 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	SORT ARG :
**	1. FILE
**	2. DIRECTORY
*/
static void	ls_arg_sort(int ac, char *av[])
{
	char	*tmp;
	t_stat	cur_stat;
	t_stat	nxt_stat;
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
}

/*
**  MANAGE FILE/DIRECTORY NAME PAST IN ARGUMENT
*/
void ls_arg(int ops[5], int ac, char *av[], t_elem *all)
{
	int 	x;
	t_stat	stat;

	x = 1;
	if (av[1] && av[1][0] == '-')
		while (av[x] && av[x][0] == '-')
			++x;
	ls_arg_sort(ac, av);
	while (av[x])
	{
		lstat(av[x], &stat);
		if (x != 1 && S_ISDIR(stat.st_mode))
			printf("%s:\n", av[x]);
		ls_start(ops, av[x++], all);
		if(av[x])
		{
			lstat(av[x], &stat);
			if (S_ISDIR(stat.st_mode))
				ft_putchar('\n');
		}
	}
	if ((av[x - 1] && av[x - 1][0] == '-') || x - 1 == 0)
		ls_start(ops, ".", all);
}
