/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:18:36 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/01 14:37:29 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_index(uintmax_t n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 16;
		++i;
	}
	return (i);
}

/*
**	CONVERT 'n' IN A HEXA NUMBER
*/

static char	*ft_itoa_16(uintmax_t n)
{
	char	*ltr;
	char	*rtr;
	int		i;

	i = ft_index(n);
	rtr = ft_strnew(i);
	ltr = "0123456789abcdef";
	if (n == 0)
		rtr[0] = '0';
	while (n)
	{
		rtr[--i] = ltr[n % 16];
		n /= 16;
	}
	free(rtr);
	return (rtr);
}

/*
**  COLLECT ARG AND STOCK HIM IN 'OUT'
*/

void		ft_ptr(t_mem *mem)
{
	void			*ptr;
	uintmax_t		p;

	ptr = (void *)va_arg(PA, void *);
	p = (uintmax_t)ptr;
	OUT = ft_itoa_16(p);
	ft_option('p', mem);
}
