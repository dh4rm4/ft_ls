/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:00:56 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:46:20 by kboddez          ###   ########.fr       */
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
