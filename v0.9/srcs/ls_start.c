/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:57:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:23:51 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	FREE LINK CONTENT FROM LINKED LIST
*/

void		ls_free(t_elem *all)
{
	free(FILE_NAME);
	free(PATH);
	free(OLD_PATH);
	free(HARD_LINK);
	free(OWNER);
	free(GROUP);
	free(SIZE);
	if (MAJOR)
		free(MAJOR);
	if (MINOR)
		free(MINOR);
}

/*
**	ls_start STEP II FOR FIRECTORY
*/

static void	ls_start_dir(int ops[11], T_STAT infos, t_elem *all)
{
	if (!ls_storage_dir(ops, all))
	{
		ls_print(1, ops, all);
		if (OP_R)
		{
			while (all && NEXT)
			{
				if (IS_DIR && (FILE_NAME[0] != '.' || OP_A || OP_AA) && \
					ft_strcmp("..", FILE_NAME) && ft_strcmp(".", FILE_NAME))
				{
					ft_putchar('\n');
					ft_putstr(join_with_char('/', OLD_PATH, FILE_NAME));
					ft_charendl(':');
					ls_start(ops, PATH, RECUR);
				}
				ls_free(all);
				all = NEXT;
			}
		}
		else
			ls_free(all);
	}
}

/*
**	BEGINING OF THE PROG
*/

int			ls_start(int ops[11], char *path, t_elem *all)
{
	T_STAT	infos;

	all = malloc(sizeof(*all));
	NEXT = NULL;
	PREV = NULL;
	OLD_PATH = ft_strdup(path);
	if (lstat(OLD_PATH, &infos) == -1)
		perror("");
	if (S_ISDIR(infos.st_mode) && !OP_D)
		ls_start_dir(ops, infos, all);
	else if (!ls_storage_file(ops, all))
		ls_print(0, ops, all);
	free(all);
	return (0);
}
