/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:37:26 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/18 11:35:02 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format_i_ii(char type, t_mem *mem)
{
	if (NB_PREC == 1 && (type == 'o' || type == 'O'))
		ft_putchar('0');
	if (NB_SIGN < NB_PREC && type != 's' && type != 'S'
		&& type != 'C' && type != 'c')
	{
		NB_SIGN = 0;
		while (NB_PREC-- > 0)
			ft_putchar('0');
	}
	if (NB_PREC > 0 && type != 's' && type != 'S'
		&& type != 'o' && type != 'O' && type != 'C' && type != 'c')
	{
		--NB_SIGN;
		--NB_READ;
		ft_putchar('0');
	}
	PRINT;
	while (NB_SIGN-- > 0)
		ft_putchar(' ');
}

/*
**	MANAGE FORMAT IF type == '-'
*/

void		ft_format_i(char type, t_mem *mem)
{
	if (CHECK == 420)
	{
		if (NB_SIGN > NB_PREC)
			--NB_SIGN;
		else
			--NB_PREC;
		ft_putchar('+');
	}
	if ((CHECK == 42 && (type == 'o' || type == 'O')
		&& type != 's' && type != 'S')
		|| (NB_PREC == 1 && type != 'o' && type != 'O'))
	{
		if (NB_PREC == 1 && type != 'S' && type != 's')
			--NB_PREC;
		if (type == 'o' || type == 'O')
			--NB_SIGN;
		if (type != 'S' && type != 's')
			ft_putchar('0');
	}
	ft_format_i_ii(type, mem);
}
