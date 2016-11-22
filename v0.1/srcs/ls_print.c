/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/22 15:16:18 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ls_print(t_dirent *rtr_dir, t_elem *all, t_path *recur)
{
	all = AFIRST;
	while (ANEXT)
	{
		if (ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
			printf("%s\n", FILE_NAME);
		all = ANEXT;
	}
	ft_strendl("\n");
	recur = RFIRST;
/*
**==================================
**	I'M HERE
**	la recursive fonctionne dans le directory du proj
**	mais pas sur un ./ft_ls ~/
**==================================
*//*
	while (recur)
	{
		printf("%s\n", RPATH);
		recur = RNEXT;
	}
*/	if (RNEXT != NULL)
		recur = RNEXT;
	if (RPREV != NULL)
		while (recur)
		{
			ls_start(RPATH);
			recur = RNEXT;
		}
	return (0);
}
