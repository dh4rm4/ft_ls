/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:42:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/18 11:43:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	format i   : '-'
**	format ii  : '+'
**	format iii : ' '
**	format iv  : '0'
**	format v   : '#'
**	format vi  : 'n'
*/

static void	ft_option_iii(char type, t_mem *mem)
{
	SIGN_CHECK = 0;
	if (NB_SIGN > 0)
		++SIGN_CHECK;
	if (SIGN == '-')
		ft_format_i(type, mem);
	else if (SIGN == '+')
		ft_format_ii(type, mem);
	else if (SIGN == ' ')
		ft_format_iii(type, mem);
	else if (SIGN == '0')
		ft_format_iv(type, mem);
	else
		ft_format_v(type, mem);
	if (*STR == ' ' || *STR == '+' || *STR == '-' || *STR == '#'
		|| *STR == '0' || (PREC_CHECK != 0 && FLAG_TYPE != 0))
		++STR;
	if (*(STR + 1) == type && *STR != type)
		++STR;
	while (*STR == '.')
		++STR;
	--STR;
}

static void	ft_option_ii(char type, t_mem *mem)
{
	if ((type == 'x' || type == 'X') && U != 0 && NB_SIGN != 0 && SIGN == '#')
		NB_READ -= 2;
	if (type == 'p' && NB_SIGN >= 2)
		NB_SIGN -= 2;
	if (NB_SIGN < 0)
		NB_SIGN = 0;
	NB_READ += NB_SIGN;
	if (NB_SIGN <= 0 && SIGN == ' ' && type != 'p' &&
		((type == 's' && (OUT && *OUT)) || type != 's')
		&& type != 'o' && type != 'O' && type != 'x' && type != 'X')
		NB_SIGN = 1;
	ft_option_iii(type, mem);
}

static void	ft_application(char type, t_mem *mem)
{
	if (NB_PREC >= ft_length(type, mem, 0) || PREC_CHECK == 0)
		NB_SIGN -= ft_length(type, mem, 0);
	else
		NB_SIGN -= NB_PREC;
}

/*
**	MANAGE THE FORMAT
*/

void		ft_option(char type, t_mem *mem)
{
	ft_options_sign_i(type, mem);
	MNB = NB_SIGN;
	if (type == 'C' && NB_SIGN > 0)
		NB_SIGN -= ft_wlen(C);
	else if ((type == 's' || type == 'S') && NB_PREC >= 0 && (OUT || WOUT) &&
(NB_SIGN > ft_length(type, mem, 0) || (NB_SIGN > NB_PREC && PREC_CHECK != 0)))
		ft_application(type, mem);
	else if (NB_PREC > -42 && NB_SIGN >= (ft_length(type, mem, 0) + NB_PREC)
			&& type != 's' && type != 'S')
		NB_SIGN = NB_SIGN - (ft_length(type, mem, 0) + NB_PREC);
	else if (SIGN == ' ' && type != 'c' && type != 'C' && type != 'u'
	&& type != 'U' && type != 'p' && D > 0 && type != 'o' && type != 'O' &&
	type != 'x' && type != 'X' && (OUT && OUT != "(null)" && *OUT != '\0'))
		NB_SIGN = 1;
	else if ((!(NB_SIGN > ft_length(type, mem, 0)) &&
			type != 's' && type != 'S') || NB_PREC > NB_SIGN)
		NB_SIGN = 0;
	else if (NB_SIGN > ft_length(type, mem, 0) && (type == 'o' || type == 'O')
			&& NB_PREC > -42)
		NB_SIGN -= ft_length(type, mem, 0);
	else if (NB_SIGN >= ft_length(type, mem, 0) && SIGN == '0')
		NB_SIGN = NB_SIGN - (ft_length(type, mem, 0) + NB_PREC);
	else
		NB_SIGN -= ft_length(type, mem, 0);
	ft_option_ii(type, mem);
}
