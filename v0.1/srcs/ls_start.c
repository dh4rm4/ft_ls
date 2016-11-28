/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:57:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/28 17:46:51 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	BEGINING OF THE PROG
*/
int	ls_start(int ops[5], char *path, t_elem *all)
{
    all = malloc(sizeof(*all));
	FIRST = all;
	NEXT = NULL;
	PREV = NULL;
	OLD_PATH = ft_strdup(path);
	if (lstat(OLD_PATH, &INFOS) == -1)
		perror("");
	if (S_ISDIR(INFOS.st_mode))
	{
		IS_DIR = 1;
		if (!ls_storage_dir(all))
		{
			ls_print(ops, all);
			if (OP_R)
			{
				all = FIRST;
				while (all)
				{
					if (IS_DIR)
					{
						ft_putchar('\n');
						ft_strendl(join_with_char('/', OLD_PATH, FILE_NAME));
						ls_start(ops, PATH, RECUR);
						//free RECUR
					}
					all = NEXT;
				}
			}
		}
	}
	else
		if (!ls_storage_file(all))
			printf("%s\n", FILE_NAME);
// FREE RECUR4
	return (0);
}
