/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_maj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:47:07 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/01 14:36:44 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_index(size_t n, int base)
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
**	CONVERT 'd' IN 'base
**	IF maj == 0 RETURN [a-f]
**	ELSE RETURN [A-F]
*/

char			*ft_itoa_maj(uintmax_t n, int base, int maj)
{
	char		*ltr;
	char		*rtr;
	int			i;

	i = ft_index(n, base);
	rtr = ft_strnew(i);
	ltr = "0123456789abcdef";
	if (maj != 0)
		ltr = "0123456789ABCDEF";
	if (n == 0)
		rtr[0] = '0';
	while (n)
	{
		rtr[--i] = ltr[n % base];
		n /= base;
	}
	free(rtr);
	return (rtr);
}
