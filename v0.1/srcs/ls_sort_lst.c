/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:28:34 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/02 15:23:01 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	CALCULATE THE LENGTH OF THE LINKED LIST
*/
static int	ls_lst_length(t_elem *all)
{
	int		timer;
	t_elem	*lst;

	timer = 0;
	lst = all;
	while (lst)
	{
		lst = lst->next;
		++timer;
	}
	return (timer + 2);
}

/*
**	SORT THE LINKED LIST WITH ALPHA
*/
static void	ls_classic_sort(t_elem *all)
{
	t_elem	*prev;
	t_elem	*current;
	int		timer;

	timer = ls_lst_length(all);
	while (timer--)
	{
		prev = NULL;
		current = all;
		while (current && current->next && current->next->file_name)
		{
			if (strcmp(current->file_name, current->next->file_name) > 0)
				ls_link_swap(prev, current, current->next, all);
			prev = current;
			current = current->next;
		}
	}
}

/*
**	SWAP TWO CHAIN LINKS
*/
void	ls_link_swap(t_elem *prev, t_elem *link_2, t_elem *link_1, t_elem *all)
{
	link_2->next = link_1->next;
	link_1->next = link_2;
	if (prev)
		prev->next = link_1;
	else
		all = link_1;
}

/*
**	START THE SORT OF THE LINKED CHAIN
*/
void	ls_sort(int ops[5], t_elem *all)
{
	if (!OP_t)
		ls_classic_sort(all);
}
