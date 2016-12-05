/* ************************************************************************** */
 /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:38:27 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/19 10:59:00 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ISOLATION OF THE FLAG TYPE
**	0 : (none)
**	1 : hh
**	2 : h
**	3 : ll
**	4 : l
**	5 : j
**	6 : z
*/

static void	ft_flag(int i, t_mem *mem)
{
	--i;
	FLAG_TYPE = 0;
	if (STR[i] == 'h' && STR[i - 1] == 'h')
		FLAG_TYPE = 1;
	else if (STR[i] == 'h')
		FLAG_TYPE = 2;
	else if (STR[i] == 'l' && STR[i - 1] == 'l')
		FLAG_TYPE = 3;
	else if (STR[i] == 'l')
		FLAG_TYPE = 4;
	else if (STR[i] == 'j')
		FLAG_TYPE = 5;
	else if (STR[i] == 'z')
		FLAG_TYPE = 6;
}

static int	ft_condition_i(int i, t_mem *mem)
{
	if (STR[i] != 's' && STR[i] != 'S' &&
		STR[i] != 'p' && STR[i] != 'd' &&
		STR[i] != 'D' && STR[i] != 'i' &&
		STR[i] != 'o' && STR[i] != 'O' &&
		STR[i] != 'u' && STR[i] != 'U' &&
		STR[i] != 'x' && STR[i] != 'X' &&
		STR[i] != 'c' && STR[i] != 'C' &&
		STR[i])
		return (0);
	return (1);
}

static int	ft_condition_ii(int i, t_mem *mem)
{
	if (STR[i] == 'i' || STR[i] == 'd' ||
		STR[i] == 'D' || STR[i] == 'o' ||
		STR[i] == 'O' || STR[i] == 'u' ||
		STR[i] == 'U' || STR[i] == 'x' ||
		STR[i] == 'X')
		return (0);
	return (1);
}

/*
**	ISOLATION OF THE TYPE
*/

static	int	ft_do(t_mem *mem)
{
	int	i;

	i = 0;
	if (*(STR + 1) == '%')
	{
		++STR;
		++NB_READ;
		ft_putchar('%');
		return (0);
	}
	while (ft_condition_i(i, mem) == 0)
		++i;
	ft_flag(i, mem);
	if (ft_condition_ii(i, mem) == 0)
		ft_int(STR[i], mem);
	else if (STR[i] == 's' || STR[i] == 'S')
		ft_string(STR[i], mem);
	else if (STR[i] == 'c' || STR[i] == 'C')
		ft_char(STR[i], mem);
	else if (STR[i] == 'p')
		ft_ptr(mem);
	++STR;
	return (0);
}

int			ft_printf(char *str, ...)
{
	t_mem		mem;
	int			check;
	int			f_check;

	mem.nb_read = 0;
	va_start(mem.pa, str);
	mem.str = str;
	mem.nb_read = 0;
	f_check = 0;
	while (*mem.str)
	{
		check = ft_check(&f_check, &mem);
		if (check == -420)
			return (0);
		if (*mem.str == '%' && check == 0)
			ft_do(&mem);
		else if (check == -1)
		{
			ft_putchar(*mem.str);
			++mem.nb_read;
		}
		++mem.str;
	}
	va_end(mem.pa);
	if (f_check == -42)
		return (0);
	return (mem.nb_read);
}
