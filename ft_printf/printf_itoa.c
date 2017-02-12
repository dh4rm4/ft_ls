/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:41:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:42:03 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nlen(int *neg, long long int n)
{
	int len;

	len = 0;
	if (n >= 0)
		*neg = 0;
	else
		*neg = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*printf_itoa(long long int n)
{
	t_itoa			it;
	char			*str;
	uintmax_t		nb;

	it.cpt = 0;
	nb = (uintmax_t)n;
	it.i = ft_nlen(&(it.neg), n) + it.neg;
	if (!(str = (char *)malloc(sizeof(*str) * (it.i + 1))))
		return (NULL);
	if (it.neg == 1)
	{
		str[0] = '-';
		nb = -1 * n;
	}
	str[0] = (nb == 0) ? '0' : str[0];
	str[it.i] = '\0';
	while (nb)
	{
		str[it.i - 1] = (nb % 10) + 48;
		nb /= 10;
		--it.i;
		++it.cpt;
	}
	free(str);
	return (str);
}
