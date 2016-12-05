/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:30:33 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/01 15:42:30 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_checku(uintmax_t u)
{
	if (u > 0 || u == 0)
		return (0);
	return (1);
}

static int	ft_nlen(uintmax_t u)
{
	int len;

	len = 0;
	if (u == 0)
		return (1);
	while (u)
	{
		u /= 10;
		len++;
	}
	return (len);
}

static void	ft_start(int *neg, int *i, int *cpt, uintmax_t u)
{
	*neg = ft_checku(u);
	*i = ft_nlen(u) + *neg;
	*cpt = 0;
}

/*
**	CONVERT 'u' TO A STRING
*/

char		*ft_unput(uintmax_t u)
{
	int		i;
	int		neg;
	int		cpt;
	char	*str;

	ft_start(&neg, &i, &cpt, u);
	str = ft_strnew(i + 1);
	if (u == 0)
		str[0] = '0';
	if (neg == 1)
	{
		str[0] = '-';
		u = (u + 1) * -1;
	}
	while (u)
	{
		if (neg == 1 && cpt == 0)
			str[--i] = u % 10 + 49;
		else
			str[--i] = u % 10 + 48;
		u /= 10;
		++cpt;
	}
	free(str);
	return (str);
}
