/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:05:51 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 11:31:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	SORT THE LINKED LIST WITH TIME
*/

void	ls_time_sort(t_elem *all)
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
			if (current->time_mem < current->next->time_mem)
				ls_link_swap(prev, current, current->next, all);
			prev = current;
			current = current->next;
		}
	}
}
