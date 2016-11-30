/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:19:09 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/30 13:42:17 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	SWAP TWO LINK FROM LINKED LIST
*/
static void	ls_swap_lst(t_elem *prev, t_elem *all)
{
	t_elem	*tmp;

	prev->next = NEXT;
	NEXT = prev;
	PREV = prev->prev;
	prev->prev = all;
	prev = PREV;
	if (PREV == NULL)
	{
		tmp = all;
		while (NEXT != NULL)
		{
			FIRST = tmp;
			all = NEXT;
		}
		all = tmp;
	}
}

/*
**	SORT LINKED LIST BY TIME
*/
t_elem	*ls_sort_time(t_elem *all)
{
	t_elem *prev;

	prev = all;
	while (NEXT)
	{
		all = NEXT;
		if (prev->infos.st_atime > ST_ATIME)
		{
			ls_swap_lst(prev, all);
			if (PREV != NULL)
				return (ls_sort_time(PREV));
			return (ls_sort_time(all));
		}
	}
	return (NULL);
}

void	ls_sort(int ops[5], t_elem *all)
{
	if (OP_t)
		ls_sort_time(all);
	all = FIRST;
//	if (OP_r)
//		ls_reverse_sort(all);
}
