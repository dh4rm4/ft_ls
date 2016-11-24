/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:57:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 17:34:41 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int	flag = 0;

/*
**	BEGINING OF THE PROG
*/
int	ls_start(char	*path, t_elem *all)
{
    all = malloc(sizeof(*all));
	FIRST = all;
	NEXT = NULL;
	PREV = NULL;
	PATH = ft_strdup(path);
	if (lstat(PATH, &INFOS) == -1)
		return (ls_exit(-1));
	if (S_ISDIR(INFOS.st_mode))
	{
		IS_DIR = 1;
		ls_storage(all);
		ls_print(all);
		if (flag == 0)
		{
			all = FIRST;
			while (all)
			{
				if (IS_DIR)
				{
					ft_putchar('\n');
					ft_strendl(ft_strjoin("./", FILE_NAME));
					ls_start(FILE_NAME, RECUR);
					//free RECUR
				}
				all = NEXT;
			}
		}
	}
// FREE RECUR4
	return (0);
}
