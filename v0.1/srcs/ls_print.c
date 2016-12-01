/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/01 09:45:25 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void	print_option_l(int x, t_elem *all)
{
	if (!x)
		printf("\033[44;32m%s %s %s %s ", PERM, HARD_LINK, OWNER, GROUP);
	else
		printf("\033[33;37m%s %s %s %s ", PERM, HARD_LINK, OWNER, GROUP);
	printf("%s %s %s\x1b[0m\n\033[33;37m", SIZE, TIME, FILE_NAME);
}

int		ls_print(int ops[5], t_elem *all)
{
	all = FIRST;
//	ls_sort(ops, all);
	while (NEXT)
	{
		if (ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{
			if (IS_DIR == 1 && OP_l)
				print_option_l(0, all);
			else if (IS_DIR == 1 && !OP_l)
				printf("\033[44;32m%s\x1b[0m\n\033[33;37m", FILE_NAME);
			else if (!IS_DIR && OP_l)
				print_option_l(42, all);
			else if (!IS_DIR && !OP_l)
				printf("\033[33;37m%s\033[33;37m\n", FILE_NAME);
		}
		all = NEXT;
	}
	return (0);
}
