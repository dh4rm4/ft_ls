/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:28:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/04 17:29:31 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**  MANAGE FILE/DIRECTORY NAME PAST IN ARGUMENT
*/
void ls_arg(int ops[5], char *av[], t_elem *all)
{
	int x;

	x = 1;
	if (av[1] && av[1][0] == '-')
		while (av[x] && av[x][0] == '-')
			++x;
	while (av[x])
		ls_start(ops, av[x++], all);
	if ((av[x - 1] && av[x - 1][0] == '-') || x - 1 == 0)
		ls_start(ops, ".", all);
}
