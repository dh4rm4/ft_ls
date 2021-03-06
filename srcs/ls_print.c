/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:16 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/20 13:29:46 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	ONLY IF OPTION "-F" IS SPECIFIED :
**	PRINT THE CHAR ACCORDING TYPE_FILE
*/

static char	ls_char_ops_f(t_elem *all)
{
	T_STAT	stat;

	lstat(PATH, &stat);
	if (S_ISDIR(stat.st_mode))
		return ('/');
	if (S_ISLNK(stat.st_mode))
		return ('@');
	if (stat.st_mode & S_IXUSR)
		return ('*');
	if (S_ISREG(stat.st_mode))
		return ('\0');
	if (S_ISSOCK(stat.st_mode))
		return ('=');
	if (OSX_WHITEOUT)
		return ('%');
	if (S_ISFIFO(stat.st_mode))
		return ('|');
	return ('\0');
}

/*
**	SEE FUNCTION "ls_print" DOC
*/

static void	print_option_l(int ops[11], t_elem *all)
{
	if (!OP_O)
		ft_printf("%s %s %s %s ", PERM, HARD_LINK, OWNER, GROUP);
	else if (OP_O)
		ft_printf("%s %s %s ", PERM, HARD_LINK, OWNER);
	if (!RDEV)
		ft_printf("%s %s %s ", SIZE, TIME, H_Y);
	else
		ft_printf("%s, %s %s %s ", MAJOR, MINOR, TIME, H_Y);
}

/*
**	SEE FUNCTION "ls_print" DOC
*/

static void	loop_instructions(int ops[11], t_elem *all)
{
	T_STAT	stat;

	lstat(PATH, &stat);
	if (FILE_NAME[0] != '.' || OP_A || OP_D || \
		(OP_AA && ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME)))
	{
		if (OP_I)
			ft_printf("%d ", INODE);
		if (OP_L || OP_O)
			print_option_l(ops, all);
		ls_color(stat);
		ft_printf("%s", FILE_NAME);
		ft_printf("%s", WHITE);
		if (OP_F && !S_ISLNK(stat.st_mode))
			ft_charendl(ls_char_ops_f(all));
		else if (OP_F && OP_L)
		{
			ft_putchar(ls_char_ops_f(all));
			ft_printf(" -> %s\n", DLINK);
		}
		else if (S_ISLNK(stat.st_mode) && OP_L)
			ft_printf(" -> %s\n", DLINK);
		else
			ft_putchar('\n');
	}
}

/*
**	REVERSE PRINT
*/

static void	ls_reverse_print(int ops[11], t_elem *all)
{
	PREV = NULL;
	while (NEXT && NEXT->file_name)
	{
		if (all->next)
			all->next->prev = all;
		all = NEXT;
	}
	while (all)
	{
		loop_instructions(ops, all);
		all = PREV;
	}
}

/*
**	ls_print + loop_instructions + print_option_l
**	PRINT THE LINKED LIST WITH OR WITHOUT OPTION(S)
**	check = 0 if call from file
**	check = 1 if call from directory
*/

int			ls_print(int check, int ops[11], t_elem *all)
{
	T_STAT	stat;

	ls_sort(ops, all);
	if (OP_L)
		lstat(OLD_PATH, &stat);
	if (OP_L && S_ISDIR(stat.st_mode))
		ft_printf("%stotal %d\n", WHITE, ls_blocks(ops, all));
	if (!OP_RR && check)
	{
		while (NEXT)
		{
			loop_instructions(ops, all);
			all = NEXT;
		}
	}
	else if (!check)
		loop_instructions(ops, all);
	else
		ls_reverse_print(ops, all);
	return (0);
}
