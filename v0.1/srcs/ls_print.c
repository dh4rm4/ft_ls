/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 16:30:57 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ls_print(t_elem *all)
{
	all = FIRST;
	while (NEXT)
	{
		if (ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{
			if (S_ISDIR(INFOS.st_mode))
				printf("\033[44;32m%s\x1b[0m\n\033[33;37m", FILE_NAME);
			else if (S_IXUSR && INFOS.st_mode)
				printf("\033[33;31m%s\n\033[33;37m", FILE_NAME);
			else
				printf("\033[33;37m%s\n", FILE_NAME);
		}
		all = NEXT;
	}
	return (0);
}
