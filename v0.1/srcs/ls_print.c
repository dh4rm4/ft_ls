/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 11:53:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ls_print(t_dirent *rtr_dir, t_elem *all, t_path *recur)
{
	all = AFIRST;
	while (ANEXT)
	{
		if (ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{
			if (S_ISDIR(AINFOS.st_mode))
				printf("\033[44;32m%s\x1b[0m\n\033[33;37m", FILE_NAME);
			else if (S_IXUSR && AINFOS.st_mode)
				printf("\033[33;31m%s\n\033[33;37m", FILE_NAME);
			else
				printf("\033[33;37m%s\n", FILE_NAME);
		}
		all = ANEXT;
	}
	recur = RFIRST;
/*	while (RNEXT)
	{
		printf("RPATH = %s\n", RPATH);
		recur = RNEXT;
	}
	recur = RFIRST;
*/	if (RNEXT != NULL)
		recur = RNEXT;
	if (RPREV != NULL)
		while (recur)
		{
			ft_putchar('\n');
			printf("\033[33;37m%s\n", RPATH);
			ls_start(RPATH);
			recur = RNEXT;
		}
	return (0);
}