/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:42:30 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/01 14:36:49 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long int	ft_neg(int d, int *neg)
{
	long int	rtr;

	rtr = (long int)d;
	*neg = 0;
	if (rtr >= 0)
		return (rtr);
	*neg = 1;
	return (-rtr);
}

static int		ft_index(long int n, int base)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= base;
		++i;
	}
	return (i);
}

/*
**	===========================
**		ft_itoa_base :
**	CONVERT 'd' IN 'base
**	===========================
*/

char			*ft_itoa_base(int d, int base)
{
	char		*ltr;
	char		*rtr;
	long int	n;
	int			neg;
	int			i;

	n = ft_neg(d, &neg);
	i = ft_index(n, base) + neg;
	rtr = ft_strnew(i);
	ltr = "0123456789abcdef";
	if (n == 0)
		rtr[0] = '0';
	if (neg == 1)
		rtr[0] = '-';
	while (n)
	{
		rtr[--i] = ltr[n % base];
		n /= base;
	}
	free(rtr);
	return (rtr);
}
