/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 10:05:37 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/14 13:08:04 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static long int	ft_checkn(int n, int *neg)
{
	long int	nb;

	nb = (long int)n;
	if (n < 0)
	{
		*neg = 1;
		return (-nb);
	}
	*neg = 0;
	return (nb);
}

static int		ft_nlen(long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			i;
	long int	nb;
	int			neg;
	char		*str;

	nb = ft_checkn(n, &neg);
	i = ft_nlen(nb) + neg;
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	str[i] = '\0';
	while (nb)
	{
		str[i - 1] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
