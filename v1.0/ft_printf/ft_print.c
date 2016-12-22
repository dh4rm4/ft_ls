/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:57:06 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/18 11:37:49 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_new_putchar(char c)
{
	write(1, &c, 1);
}

/*
**	PRINT IF 'type' == 'S' || ('s' && (PREC_CHECK != 0))
*/

static void	ft_putstr_str(char type, t_mem *mem)
{
	int	i;

	i = 0;
	if (type != 'S')
	{
		while (i < NB_PREC && OUT[i])
		{
			++NB_READ;
			ft_putchar(OUT[i++]);
		}
	}
	else if (PREC_CHECK != 0)
		while (i < NB_PREC && WOUT[i])
			ft_putwchar(WOUT[i++], mem);
	else
		while (WOUT[i])
			ft_putwchar(WOUT[i++], mem);
}

/*
**  MANAGE THE FORMAT IF SIGN == '-'
*/

void		ft_print(char type, t_mem *mem)
{
	if (type == 'c')
	{
		++NB_READ;
		ft_new_putchar(C);
	}
	else if (type == 'C')
		ft_putwchar(C, mem);
	else
	{
		if (type == 'p')
			ft_putstr_cpt(type, mem);
		else if ((type == 's' && PREC_CHECK != 0) || type == 'S')
			ft_putstr_str(type, mem);
		else
		{
			if (D < 0 && *OUT == '-' && SIGN == 'n' && PREC_CHECK != 0)
				++OUT;
			ft_putstr_cpt(type, mem);
		}
		if (SIGN == '#' && CHECK == 42)
			while (NB_SIGN-- > 0)
				ft_putchar(' ');
	}
}
