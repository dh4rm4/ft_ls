/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:29:44 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/19 15:04:14 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	COMPLETE 'ops' WITH THE WRIGHT OPTIONS
*/

static void	ls_redirect_option(char opt, int ops[5])
{
	ops[0] = (opt == 'l' || ops[0] == 1) ? 1 : 0;
	ops[1] = (opt == 'R' || ops[1] == 1) ? 1 : 0;
	ops[2] = (opt == 'a' || ops[2] == 1) ? 1 : 0;
	ops[3] = (opt == 'r' || ops[3] == 1) ? 1 : 0;
	ops[4] = (opt == 't' || ops[4] == 1) ? 1 : 0;
	ops[5] = (opt == 'A' || ops[5] == 1) ? 1 : 0;
	ops[6] = (opt == 'd' || ops[6] == 1) ? 1 : 0;
	ops[7] = (opt == 'F' || ops[7] == 1) ? 1 : 0;
	ops[8] = (opt == 'i' || ops[8] == 1) ? 1 : 0;
	ops[9] = (opt == 'o' || ops[9] == 1) ? 1 : 0;
	ops[10] = (opt == 'u' || ops[10] == 1) ? 1 : 0;
}

/*
**	MANAGE OPTIONS ERROR
*/

static void	ls_arg_error(char opt)
{
	ft_printf("ls: illegal option -- %c\n", opt);
	ft_printf("usage: ls [lRaArtdFiou]\n");
	exit(-1);
}

/*
**	MANAGE OPTIONS PAST IN ARGUMENT
*/

static int	ls_manage_arg(int ac, char *av[], int ops[11])
{
	size_t	x;
	size_t	y;

	x = 0;
	while (av[++x])
	{
		y = 0;
		if (av[x][0] == '-')
			while (av[x] && av[x][++y])
			{
				if (av[x][y] != 'l' && av[x][y] != 'R' && av[x][y] != 'a'
					&& av[x][y] != 't' && av[x][y] != '-' && av[x][y] != 'r' \
					&& av[x][y] != 'A' && av[x][y] != 'd' && av[x][y] != 'F' \
					&& av[x][y] != 'i' && av[x][y] != 'o' && av[x][y] != 'u')
					ls_arg_error(av[x][y]);
				else
					ls_redirect_option(av[x][y], ops);
			}
	}
	return (0);
}

int			main(int ac, char *av[])
{
	int		ops[11];
	t_elem	*all;

	ops[0] = 0;
	ops[1] = 0;
	ops[2] = 0;
	ops[3] = 0;
	ops[4] = 0;
	if (av[1] && av[1][0] == '-')
		ls_manage_arg(ac, av, ops);
	ls_arg(ops, ac, av, all);
	return (0);
}
