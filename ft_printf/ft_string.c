/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:54:32 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/05 14:25:47 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_string(char type, t_mem *mem)
{
	++STR;
	if (type == 's' && FLAG_TYPE == 4)
		type = 'S';
	if (type == 's')
	{
		OUT = va_arg(PA, char*);
		WOUT = NULL;
	}
	else
	{
		WOUT = va_arg(PA, wchar_t*);
		OUT = NULL;
	}
	if (type == 's' && !OUT)
		OUT = "(null)";
	else if (type == 'S' &&
			(!WOUT || (WOUT[0] == '(' && WOUT[1] == 'n' && WOUT[2] == 'u' &&
						WOUT[3] == 'l' && WOUT[4] == 'l' && WOUT[5] == ')')))
	{
		type = 's';
		OUT = "(null)";
	}
	else if (WOUT && !(WOUT))
		WOUT = L"(null)";
	ft_option(type, mem);
}
