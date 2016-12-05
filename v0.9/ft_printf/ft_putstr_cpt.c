/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cpt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 09:55:12 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/12 11:36:09 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putptr(t_mem *mem)
{
	if (SIGN != '0')
		ft_putstr("0x");
	NB_READ += 2;
	if (*OUT == '0' && PREC_CHECK != 0 && NB_PREC <= 0)
		return (0);
	while (NB_PREC-- > 0)
		ft_putchar('0');
	while (OUT && *OUT)
	{
		ft_putchar(*OUT);
		++OUT;
		++NB_READ;
	}
	if (NB_SIGN != 0 && SIGN == '+')
	{
		NB_READ -= NB_SIGN;
		NB_SIGN = 0;
	}
	return (0);
}

int			ft_putstr_cpt(char type, t_mem *mem)
{
	if (type == 'p')
		return (ft_putptr(mem));
	else
	{
		if (D < 0 && SIGN == '0')
			++OUT;
		if (NB_PREC <= -42 && *OUT == '0')
			return (-1);
		while (OUT && *OUT)
		{
			ft_putchar(*OUT);
			++OUT;
			++NB_READ;
		}
	}
	return (0);
}
