/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:47:58 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:43:22 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_arg_int_i(char type, t_mem *mem)
{
	if (FLAG_TYPE == 1)
	{
		if (type == 'O')
			D = va_arg(PA, int);
		else if (type == 'o')
		{
			D = (short unsigned int)va_arg(PA, int);
			D %= 256;
		}
		else if (type == 'D')
			D = va_arg(PA, int);
		else
			D = (char)va_arg(PA, int);
	}
	else if (FLAG_TYPE == 2)
	{
		if (type == 'o' || type == 'O')
			D = (short unsigned int)va_arg(PA, int);
		else if (type == 'D')
			D = va_arg(PA, int);
		else
			D = (short int)va_arg(PA, int);
	}
}

static void	ft_arg_int_ii(char type, t_mem *mem)
{
	if (FLAG_TYPE == 3 || (type == 'D' && FLAG_TYPE != 6))
		D = va_arg(PA, long long int);
	else if (FLAG_TYPE == 4)
		D = va_arg(PA, long int);
	else if (FLAG_TYPE == 5)
		D = va_arg(PA, intmax_t);
	else if (FLAG_TYPE == 6)
	{
		if (type == 'o' || type == 'O')
			U = va_arg(PA, long long int);
		else if (type == 'D')
			U = va_arg(PA, int);
		else
			U = va_arg(PA, size_t);
	}
	else
	{
		if (type != 'o' && type != 'O' && type != 'D')
			D = va_arg(PA, int);
		else if (type == 'O')
			D = va_arg(PA, long long int);
		else
			D = (unsigned int)va_arg(PA, long long int);
	}
}

static void	ft_arg_un_int(char type, t_mem *mem)
{
	if (FLAG_TYPE == 1 && type != 'U')
		U = (unsigned char)va_arg(PA, int);
	else if (FLAG_TYPE == 2 && type != 'U')
		U = (unsigned int)va_arg(PA, unsigned int);
	else if (FLAG_TYPE == 3 && type != 'U')
		U = va_arg(PA, unsigned long long int);
	else if (FLAG_TYPE == 4 && type != 'U')
		U = (unsigned long int)va_arg(PA, uintmax_t);
	else if (FLAG_TYPE == 5 && type != 'U')
		U = (uintmax_t)va_arg(PA, uintmax_t);
	else if (FLAG_TYPE == 0 && type != 'U')
		U = (unsigned int)va_arg(PA, size_t);
	else
		U = va_arg(PA, long long int);
}

void		ft_int(char type, t_mem *mem)
{
	if (type != 'u' && type != 'U' && type != 'x' && type != 'X' &&
		(FLAG_TYPE == 1 || FLAG_TYPE == 2))
		ft_arg_int_i(type, mem);
	else if (type != 'u' && type != 'U' && type != 'x' && type != 'X' &&
			FLAG_TYPE != 1 && FLAG_TYPE != 2)
		ft_arg_int_ii(type, mem);
	else
		ft_arg_un_int(type, mem);
	if (type == 'o' || type == 'O')
		OUT = (FLAG_TYPE != 6) ? ft_itoa_maj(D, 8, 0) : ft_itoa_maj(U, 8, 0);
	else if (type == 'X')
		OUT = ft_itoa_maj(U, 16, 42);
	else if (type == 'x')
		OUT = ft_itoa_maj(U, 16, 0);
	else if ((type == 'd' || type == 'D' || type == 'i') && FLAG_TYPE == 6)
		OUT = printf_itoa(U);
	else if (type == 'u' || type == 'U' ||
			((type == 'd' || type == 'D' || type == 'i') &&
			FLAG_TYPE == 6))
		OUT = ft_unput(U);
	else
		OUT = printf_itoa(D);
	ft_option(type, mem);
}
