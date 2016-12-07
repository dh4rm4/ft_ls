/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:50:44 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/06 12:10:52 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_boid(char c, t_mem *mem)
{
	while (*STR >= '0' && *STR <= '9')
	{
		NB_SIGN = NB_SIGN * 10 + (*STR - '0');
		++STR;
	}
	NB_READ += NB_SIGN;
	if (NB_READ == 0)
		++NB_READ;
	--NB_SIGN;
	if (SIGN == '-')
		ft_putchar(c);
	if (SIGN == '0' && (*STR != '.' || NB_SIGN != 0))
		while (--NB_SIGN >= 0)
			ft_putchar(SIGN);
	else if (*STR != '.')
		while (--NB_SIGN >= 0)
			ft_putchar(' ');
	if (SIGN != '-')
		ft_putchar(c);
}

static int	ft_modulo(char c, t_mem *mem)
{
	NB_SIGN = 0;
	SIGN = ' ';
	++STR;
	while (!(*STR >= '0' && *STR <= '9') && *STR != '%' && *STR != '.')
	{
		if (*STR == '-')
			SIGN = '-';
		++STR;
	}
	if (*STR == '0' && !(*(STR - 1) >= '0' && *(STR - 1) <= '9') && SIGN != '-')
		SIGN = '0';
	if (*STR != '%')
		ft_boid(c, mem);
	else
	{
		++NB_READ;
		while (*STR != '%' && *STR)
			++STR;
		ft_putchar('%');
	}
	if (*STR == '.')
		++STR;
	return (420);
}

static int	ft_condition_i(int i, t_mem *mem)
{
	if (STR[i] == 's' || STR[i] == 'S' ||
		STR[i] == 'p' || STR[i] == 'd' ||
		STR[i] == 'D' || STR[i] == 'i' ||
		STR[i] == 'o' || STR[i] == 'O' ||
		STR[i] == 'u' || STR[i] == 'U' ||
		STR[i] == 'x' || STR[i] == 'X' ||
		STR[i] == 'c' || STR[i] == 'C')
		return (0);
	return (1);
}

static int	ft_condition_ii(int i, t_mem *mem)
{
	if ((STR[i] < 'A' || STR[i] > 'Z') &&
		(STR[i] < 'a' || STR[i] > 'g') &&
		(STR[i] < 'm' || STR[i] > 'y') &&
		STR[i] != 'i' && STR[i] != 'k' &&
		STR[i] != '%' && STR[i])
		return (0);
	return (1);
}

int			ft_check(t_mem *mem)
{
	int	i;

	i = 0;
	if (*STR == '%')
	{
		i = 1;
		while (ft_condition_ii(i, mem) == 0)
			++i;
		if (STR[i] == '%')
			return (ft_modulo(STR[i], mem));
		else if (ft_condition_i(i, mem) == 0)
			return (0);
		else if (STR[i] && ((STR[i - 1] >= '0' && STR[i - 1] <= '9')
							|| STR[i - 1] == '.'))
			return (ft_modulo(STR[i], mem));
		else if (!STR[i] && STR[i - 1] == '0')
			return (-420);
		else if (!STR[i])
			return (-42);
		if (*(STR + 1) == ' ')
			++STR;
		++STR;
		return (-1);
	}
	return (-1);
}
