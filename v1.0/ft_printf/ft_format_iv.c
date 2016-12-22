/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_iv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:37:46 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/11 07:19:43 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format_iv_end(char type, t_mem *mem)
{
	if (PREC_CHECK == 0)
		while (NB_SIGN-- > 0)
			ft_putchar('0');
	else if (NB_SIGN == 1 && D < 0)
		ft_putchar('0');
	else if (NB_PREC)
		while (NB_SIGN-- > 0)
			ft_putchar(' ');
	else
		while (NB_SIGN-- > 0)
			ft_putchar('0');
	if (PREC_CHECK != 0)
		while (NB_PREC-- > 0)
			ft_putchar('0');
	PRINT;
}

/*
**  MANAGE THE FORMAT IF SIGN == '0'
*/

void		ft_format_iv(char type, t_mem *mem)
{
	if (CHECK == 42)
	{
		--NB_SIGN;
		if (NB_PREC)
			--NB_PREC;
		ft_putchar('+');
	}
	else if (D < 0)
	{
		++NB_READ;
		ft_putchar('-');
	}
	if (type == 'p')
		ft_putstr("0x");
	ft_format_iv_end(type, mem);
}
