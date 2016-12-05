/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:37:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/18 11:34:26 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_neg(t_mem *mem)
{
	++NB_READ;
	++OUT;
	ft_putchar('-');
}

static int	ft_condition(char type)
{
	if (type != 'p' && type != 'u' && type != 'U' && type != 'S' && type != 's'
		&& type != 'c' && type != 'C' && type != 'o' && type != 'O'
		&& type != 'x' && type != 'X')
		return (1);
	return (-1);
}

/*
** CONTINUATION OF ft_format_ii
*/

static void	ft_format_ii_bis(char type, t_mem *mem)
{
	if (D < 0)
		ft_neg(mem);
	if (D > 0 && ft_condition(type) == 1)
		ft_putchar('+');
	else if ((type == 'd' || type == 'i') && D >= 0)
		ft_putchar('+');
	if ((CHECK == 420 || (PREC_CHECK != 0 && NB_PREC > 0)) && type != 'p'
		&& type != 's' && type != 'S' && type != 'C' && type != 'c')
	{
		if (CHECK != 42)
			while (NB_SIGN-- > 0 || NB_PREC-- > 0)
				ft_putchar('0');
		else
			while (NB_PREC-- > 0)
				ft_putchar('0');
	}
	PRINT;
	while (NB_SIGN-- > 0)
		ft_putchar(' ');
}

/*
**	MANAGE THE FORMAT IF SIGN == '+'
*/

void		ft_format_ii(char type, t_mem *mem)
{
	if (ft_condition(type) == 1 && D > 0)
		++NB_READ;
	else if ((type == 'd' || type == 'i' || type == 'D') && D >= 0)
		++NB_READ;
	if (NB_SIGN > NB_PREC && (D > 0 || (PREC_CHECK == 0 && D >= 0)) &&
		ft_length(type, mem, 1) < MNB
		&& ft_condition(type) == 1)
		--NB_READ;
	if (D >= 0 && NB_SIGN > 0 && PREC_CHECK != 0 && ft_condition(type) == 1)
	{
		if (NB_PREC > 0 && NB_PREC > NB_SIGN)
			--NB_READ;
		if (NB_SIGN > 1 && (D != 0 || (NB_PREC != 0 && D >= 0)))
			--NB_SIGN;
	}
	else if ((type == 'd' || type == 'D' || type == 'i') && D >= 0)
		--NB_SIGN;
	if (CHECK != 420 && CHECK != 42 && type != 'p')
		while (NB_SIGN-- > 0)
			ft_putchar(' ');
	ft_format_ii_bis(type, mem);
}
