/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:00:56 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 11:51:26 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	COUNT THE NBR OF CHAR IN 'd'
*/

int	ft_nbr_length(int d)
{
	int	rtr;

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
