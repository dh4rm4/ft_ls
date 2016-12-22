/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:38:07 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/11 11:13:02 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format_v_ii(char type, t_mem *mem)
{
	if ((type == 'o' || type == 'O') && D != 0 && NB_PREC <= 0)
	{
		if (SIGN == '#' && SIGN_CHECK != 0)
			--NB_READ;
		++NB_READ;
		ft_putchar('0');
	}
	else if (type == 'x' && U != 0)
		ft_putstr("0x");
	else if (type == 'X' && U != 0)
		ft_putstr("0X");
	if (PREC_CHECK != 0)
		while (NB_PREC-- > 0)
			ft_putchar('0');
	else if (CHECK == 420)
		while (NB_SIGN-- > 0)
			ft_putchar('0');
	PRINT;
}

/*
**  MANAGE THE FORMAT IF SIGN == '#
*/

static void	ft_format_v_i(char type, t_mem *mem)
{
	--NB_SIGN;
	if ((type == 'x' || type == 'X') && U != 0)
	{
		--NB_SIGN;
		NB_READ += 2;
	}
	if (CHECK != 420 && CHECK != 42)
		while (NB_SIGN-- > 0)
			ft_putchar(' ');
	if (D < 0 && type != 'x' && type != 'X')
		ft_putchar('-');
	ft_format_v_ii(type, mem);
}

/*
**  MANAGE THE FORMAT IF SIGN == 'n'
*/

static void	ft_format_vi(char type, t_mem *mem)
{
	if (*STR == ' ')
	{
		ft_putchar(' ');
		++NB_READ;
	}
	if (NB_PREC >= NB_SIGN && type != 's' && type != 'S')
	{
		NB_READ -= NB_SIGN;
		NB_SIGN = 0;
	}
	while (NB_SIGN-- > 0)
		ft_putchar(' ');
	if (D < 0 && (OUT && *OUT == '-') && PREC_CHECK != 0)
	{
		++NB_READ;
		ft_putchar('-');
	}
	if (PREC_CHECK != 0 && type != 's' && type != 'S' && type != 'c'
		&& type != 'C' && type != 'p')
		while (NB_PREC-- > 0)
			ft_putchar('0');
	PRINT;
}

void		ft_format_v(char type, t_mem *mem)
{
	if (SIGN == '#' && (type == 'o' || type == 'x' || type == 'X'
						|| type == 'O'))
		ft_format_v_i(type, mem);
	else
		ft_format_vi(type, mem);
}
