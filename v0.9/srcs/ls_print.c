/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 11:47:21 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	SEE FUNCTION "ls_print" DOC
*/

static void	print_option_l(int x, t_elem *all)
{
	if (!x)
		printf("\033[44;32m%s %s %s %s ", PERM, HARD_LINK, OWNER, GROUP);
	else
		printf("\033[33;37m%s %s %s %s ", PERM, HARD_LINK, OWNER, GROUP);
	if (!RDEV)
		printf("%s %s %s\x1b[0m\n\033[33;37m", SIZE, TIME, FILE_NAME);
	else
		printf("%s, %s %s %s\x1b[0m\n\033[33;37m", MAJOR, MINOR, TIME, \
			FILE_NAME);
}

/*
**	SEE FUNCTION "ls_print" DOC
*/

static void	loop_instructions(int ops[5], t_elem *all)
{
	if (FILE_NAME[0] != '.' || OP_A)
	{
		if (IS_DIR == 1 && OP_L)
			print_option_l(0, all);
		else if (IS_DIR == 1 && !OP_L)
			printf("\033[44;32m%s\x1b[0m\n\033[33;37m", FILE_NAME);
		else if (!IS_DIR && OP_L)
			print_option_l(42, all);
		else if (!IS_DIR && !OP_L)
			printf("\033[33;37m%s\033[33;37m\n", FILE_NAME);
	}
}

/*
**	CALCULATE THE TOTAL NUMBER OF BLOCKS
**	FOR A DIRECTORY
*/

static int	ls_blocks(t_elem *all)
{
	int	total_blks;

	total_blks = 0;
	while (NEXT)
	{
		total_blks += BLOCKS;
		all = NEXT;
	}
	return (total_blks);
}

/*
**	REVERSE PRINT
*/

static void	ls_reverse_print(int ops[5], t_elem *all)
{
	while (NEXT && NEXT->file_name)
	{
		if (all->next)
			all->next->prev = all;
		all = NEXT;
	}
	while (PREV != NULL)
	{
		loop_instructions(ops, all);
		all = PREV;
	}
}

/*
**	ls_print + loop_instructions + print_option_l
**	PRINT THE LINKED LIST WITH OR WITHOUT OPTION(S)
*/

int			ls_print(int ops[5], t_elem *all)
{
	T_STAT	stat;

	ls_sort(ops, all);
	if (OP_L)
		lstat(OLD_PATH, &stat);
	if (OP_L && S_ISDIR(stat.st_mode))
		printf("total %d\n", ls_blocks(all));
	if (!OP_RR)
		while (NEXT)
		{
			loop_instructions(ops, all);
			all = NEXT;
		}
	else
		ls_reverse_print(ops, all);
	return (0);
}
