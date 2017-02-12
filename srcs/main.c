/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:29:44 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/20 14:52:53 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	COMPLETE 'ops' WITH THE WRIGHT OPTIONS
*/

static void	ls_redirect_option(char opt, int ops[5])
{
	ops[0] = (cmpc(opt, 'l') || ops[0] == 1) ? 1 : 0;
	ops[1] = (cmpc(opt, 'R') || ops[1] == 1) ? 1 : 0;
	ops[2] = (cmpc(opt, 'a') || ops[2] == 1) ? 1 : 0;
	ops[3] = (cmpc(opt, 'r') || ops[3] == 1) ? 1 : 0;
	ops[5] = (cmpc(opt, 'A') || ops[5] == 1) ? 1 : 0;
	ops[6] = (cmpc(opt, 'd') || ops[6] == 1) ? 1 : 0;
	ops[7] = (cmpc(opt, 'F') || ops[7] == 1) ? 1 : 0;
	ops[8] = (cmpc(opt, 'i') || ops[8] == 1) ? 1 : 0;
	ops[9] = (cmpc(opt, 'o') || ops[9] == 1) ? 1 : 0;
	ops[10] = (cmpc(opt, 'u') || ops[10] == 1) ? 1 : 0;
	ops[4] = ((cmpc(opt, 't') || ops[4] == 1) && !ops[10]) ? 1 : 0;
}

/*
**	OUTPUT OPTIONS ERROR
*/

static void	ls_arg_error(char opt)
{
	ft_printf("ls: illegal option -- %c\n", opt);
	ft_printf("usage: ls [lRaArtdFiou]\n");
	exit(-1);
}

/*
**	CHECK IF THE NUMBER OF DASH IN OPTION IS VALID
*/

static void	ls_check_nb_dash_in_option(size_t x, char *av[])
{
	if (cmpc(av[x][0], '-') && av[x][1] && cmpc(av[x][1], '-') &&
		av[x][2] && cmpc(av[x][2], '-') ||
		(cmpc(av[x][0], '-') && !av[x][1]))
		ls_arg_error('-');
}

/*
**	CHECK IF 'c' IS A VALID OPTION
*/

static int	ls_check_option(char c)
{
	if (cmpc(c, 'l') && cmpc(c, 'R') && cmpc(c, 'a')
		&& cmpc(c, 't') && cmpc(c, '-') && cmpc(c, 'r')
		&& cmpc(c, 'A') && cmpc(c, 'd') && cmpc(c, 'F')
		&& cmpc(c, 'i') && cmpc(c, 'o') && cmpc(c, 'u'))
		return (0);
	return (1);
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
		ls_check_nb_dash_in_option(x, av);
		if (cmpc(av[x][0], '-'))
			while (av[x] && av[x][++y])
			{
				if (!ls_check_option(av[x][y]))
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
	if (av[1] && cmpc(av[1][0], '-'))
		ls_manage_arg(ac, av, ops);
	ls_arg(ops, ac, av, all);
	return (0);
}
