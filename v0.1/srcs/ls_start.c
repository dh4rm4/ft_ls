/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:57:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 10:18:54 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	BEGINING OF THE PROG
*/
int	ls_start(int ops[5], char *path, t_elem *all)
{
	t_stat	infos;

	all = malloc(sizeof(*all));
	NEXT = NULL;
	PREV = NULL;
	OLD_PATH = ft_strdup(path);
	if (lstat(OLD_PATH, &infos) == -1)
		perror("");
	if (S_ISDIR(infos.st_mode))
	{
		if (!ls_storage_dir(all))
		{
			ls_print(ops, all);
			if (OP_R)
			{
				while (all && NEXT)
				{
					if (IS_DIR && FILE_NAME[0] != '.')
					{
						ft_putchar('\n');
						ft_strendl(join_with_char('/', OLD_PATH, FILE_NAME));
						ls_start(ops, PATH, RECUR);
					}
					all = NEXT;
				}
			}
		}
	}
	else
		if (!ls_storage_file(all))
			printf("%s\n", FILE_NAME);
	return (0);
}
