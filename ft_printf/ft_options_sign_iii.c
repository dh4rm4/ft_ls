/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_sign_iii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:56:24 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:55:01 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_options_sign_iii(t_mem *mem)
{
	if ((SIGN == '#' && *STR == '0' && CHECK == 0) ||
		(SIGN == '-' && *(STR - 1) == '+') ||
		(SIGN == ' ' && *STR == '0'))
	{
		CHECK = 420;
		++STR;
	}
	else if (SIGN == '+' && *STR == '0')
	{
		CHECK = 420;
		++STR;
	}
	while (!(*STR >= '0' && *STR <= '9') && *STR && ft_test(*STR) == 1)
		++STR;
	if (printf_isdigit(*STR) == 1)
		NB_SIGN = 0;
	while (*STR >= '0' && *STR <= '9')
	{
		NB_SIGN = NB_SIGN * 10 + *STR - '0';
		++STR;
	}
	if (SIGN == '+' && (*STR == '-' || *STR == ' ' || *STR == '#'))
		while (*(++STR) >= '0' && *(STR) <= '9')
			;
}
