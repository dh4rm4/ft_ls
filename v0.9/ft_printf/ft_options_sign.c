/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 10:34:23 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:54:43 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_nbr(t_mem *mem)
{
	while (printf_isdigit(*STR) == 1)
	{
		NB_SIGN = NB_SIGN * 10 + *STR - '0';
		++STR;
	}
}

static int	ft_condition(char type)
{
	if (type == 'd' || type == 'i' || type == 'o' || type == 'O' || type == 'u'
		|| type == 'U')
		return (1);
	return (-1);
}

static void	ft_options_sign_ii(char type, t_mem *mem)
{
	if (SIGN == 'n' || (SIGN != 'n' && *STR != '0'))
		ft_nbr(mem);
	while (!(*STR >= '0' && *STR <= '9') && ft_test(*STR) == 1)
	{
		if (SIGN == ' ' && *STR == '+')
			CHECK = 420;
		else if ((SIGN == '#' && *STR == '-') || (SIGN == '-' && *STR == '#')
	|| (SIGN == '0' && *STR == '+' && D > 0) || (SIGN == '-' && *STR == '+'))
			CHECK = 42;
		else
			CHECK = 0;
		if ((SIGN == '0' && *STR == '-') || (SIGN == '+' && *STR == '-'
			&& type == ('S' | 's' | 'c' | 'C')))
			SIGN = '-';
		else if (SIGN != '#' && *STR == '#' && type == ('o' | 'O' | 'x' | 'X'))
			SIGN = '#';
		else if (*STR == '+' && (SIGN == '-' || SIGN == 'n'))
			SIGN = '+';
		if (*STR == ' ' && (*(STR + 1) >= '0' && *(STR - 1) <= '9'))
			NB_SIGN = 1;
		++STR;
	}
	ft_options_sign_iii(mem);
}

static void	ft_checkar(t_mem *mem)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (STR[i] != 's' && STR[i] != 'S' && STR[i] != 'p' && STR[i] != 'd' &&
			STR[i] != 'D' && STR[i] != 'i' && STR[i] != 'o' && STR[i] != 'O' &&
			STR[i] != 'u' && STR[i] != 'U' && STR[i] != 'x' && STR[i] != 'X' &&
			STR[i] != 'c' && STR[i] != 'C' && check < 2 && STR[i])
	{
		if (STR[i] == '+' || STR[i] == '-' || STR[i] == '#' || STR[i] == ' ')
			++check;
		++i;
	}
	if (check == 2)
		while (*STR >= '0' && *STR <= '9')
			++STR;
}

/*
**	ft_options_sign_i/ii/iii
**	MANAGE FORMAT
*/

int			ft_options_sign_i(char type, t_mem *mem)
{
	CHECK = 0;
	if (*STR == '%')
		++STR;
	ft_checkar(mem);
	NB_SIGN = 0;
	if (printf_isdigit(*STR) == 1 && ft_condition(type) == 1 && *STR != '0')
		ft_nbr(mem);
	if (*STR == '-' || *STR == '+' || *STR == '0' || *STR == ' ' || *STR == '#')
	{
		SIGN = *STR;
		++STR;
	}
	else
		SIGN = 'n';
	ft_options_sign_ii(type, mem);
	NB_PREC = 0;
	PREC_CHECK = 0;
	if (*STR == '.')
		ft_precision(type, mem);
	if (NB_PREC >= 0 && type != 's' && type != 83 && type != 'c' && type != 67)
		NB_READ += NB_PREC;
	if (SIGN == '#' &&
		(type == 's' || type == 'S'))
		SIGN = 'n';
	return (0);
}
