/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:20:01 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/12 10:26:55 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ReCOUNT NB_SIGN WHEN WCHAR WRITE ON MANY BITS
*/

static int	ft_wstring(int nb_prec, wchar_t *wstr, t_mem *mem)
{
	int checker;
	int prev_checker;
	int i;

	checker = 0;
	i = 0;
	while (checker < nb_prec && wstr[i])
	{
		prev_checker = checker;
		checker += ft_wlen(wstr[i]);
		++i;
	}
	if (checker > nb_prec)
		--i;
	if (NB_SIGN > nb_prec)
		NB_SIGN = NB_SIGN - (checker - prev_checker - i);
	else
		NB_SIGN = NB_SIGN - (checker - (prev_checker - i));
	return (i);
}

/*
**	MANAGE THE ARGV WITH THE PRECISION
*/

void		ft_precision(char type, t_mem *mem)
{
	++STR;
	++PREC_CHECK;
	while (*STR >= '0' && *STR <= '9')
	{
		NB_PREC = NB_PREC * 10 + *STR - '0';
		++STR;
	}
	if (NB_PREC == 0 && type != 's' && type != 'S')
		NB_PREC = -42;
	if (type == 'S' || type == 's')
		NB_PREC -= ft_length(type, mem, 1);
	else if (NB_PREC != -42)
		NB_PREC -= ft_length(type, mem, 0);
	if ((type == 'i' || type == 'd' ||
		type == 'D') && D < 0)
		++NB_PREC;
	if ((type != 'c' && type != 'C' && ((NB_PREC < 0 && NB_PREC != -42)
		|| (OUT && (!(*OUT))))) || (((type == 'c' || type == 'C') && !C)) ||
		(NB_PREC == -42 && !D && (type == 'o' || type == 'O') && SIGN == '#'))
		NB_PREC = 0;
	if (type == 'S' && NB_PREC > 0)
		NB_PREC = ft_wstring(NB_PREC, WOUT, mem);
}
