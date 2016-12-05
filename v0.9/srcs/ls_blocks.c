/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:40:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 19:41:26 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**  CALCULATE THE TOTAL NUMBER OF BLOCKS
**  FOR A DIRECTORY
*/

int	ls_blocks(t_elem *all)
{
	int total_blks;

	total_blks = 0;
	while (NEXT)
	{
		total_blks += BLOCKS;
		all = NEXT;
	}
	return (total_blks);
}
