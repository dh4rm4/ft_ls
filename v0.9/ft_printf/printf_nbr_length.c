/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:04:55 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 20:05:08 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**   COUNT THE NBR OF CHAR IN 'd'
*/

int	printf_nbr_length(int d, t_mem *mem)
{
	int	rtr;

	if (NB_PREC <= 0 && d == 0 && PREC_CHECK > 0)
		return (0);
	rtr = 0;
	if (d < 0)
		++rtr;
	if (d == 0)
		return (1);
	while (d)
	{
		d /= 10;
		++rtr;
	}
	return (rtr);
}
