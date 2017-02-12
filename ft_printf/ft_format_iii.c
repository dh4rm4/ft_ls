/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_iii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:37:32 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/01 10:50:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**  MANAGE THE FORMAT IF SIGN == ' '
*/

void	ft_format_iii(char type, t_mem *mem)
{
	NB_READ = (NB_SIGN == 0 && D < 0) ? NB_READ - 1: NB_READ;
	if (NB_SIGN > 0 || (NB_SIGN == 0 && D >= 0))
	{
		if (type != 'c' && type != 'C' && type != 'u' && type != 'U'
			&& type != 'p' && CHECK != 420 && type != 'o' && type != 'O'
			&& type != 'x' && type != 'X'
			&& (OUT && *OUT && *OUT != '-' && ft_strcmp(OUT, "(null)")))
			ft_putchar(' ');
		if (CHECK != 420)
			while (--NB_SIGN > 0)
				ft_putchar(' ');
		else
		{
			if (NB_SIGN - 1 > 0)
				ft_putchar(' ');
			while (--NB_SIGN > 0)
				ft_putchar('0');
		}
		if (CHECK == 420 && D > 0)
			ft_putchar('+');
	}
	if (PREC_CHECK != 0)
		while (NB_PREC-- > 0)
			ft_putchar('0');
	PRINT;
}
