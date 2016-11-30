/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/30 14:11:47 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ls_print(int ops[5], t_elem *all)
{
	all = FIRST;
//	ls_sort(ops, all);
	while (NEXT)
	{
		if (ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{
			if (IS_DIR == 1 && OP_l)
				printf("\033[44;32m%s\x1b[0m\n\033[33;37m", F_FILE);
			else if (IS_DIR == 1 && !OP_l)
				printf("\033[44;32m%s\x1b[0m\n\033[33;37m", FILE_NAME);
			else if (!IS_DIR && OP_l)
				printf("\033[33;37m%s\033[33;37m\n", F_FILE);
			else if (!IS_DIR && !OP_l)
				printf("\033[33;37m%s\033[33;37m\n", FILE_NAME);
		}
		all = NEXT;
	}
	return (0);
}
