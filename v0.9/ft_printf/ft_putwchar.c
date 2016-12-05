/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 09:11:11 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/11 15:45:38 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	49280      = 110x xxxx 10xx xxxx
**	14712960   = 1110 xxxx 10xx xxxx 10xx xxxx
**	4034953344 = 111 xxxx 10xx xxxx 10xx xxxx 10xx xxxx
*/

static void			ft_mask(t_bin *o)
{
	o->mask0 = 49280;
	o->mask1 = 14712960;
	o->mask2 = 4034953344;
}

static void			ft_putwchar_ii(unsigned char final, unsigned int bin_sign,
								t_bin o, t_mem *mem)
{
	o.bin1 = (bin_sign << 26) >> 26;
	o.bin0 = ((bin_sign >> 6) << 27) >> 27;
	final = (o.mask0 >> 8) | o.bin0;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask0 << 24) >> 24) | o.bin1;
	write(1, &final, 1);
	++NB_READ;
}

static void			ft_putwchar_iii(unsigned char final, unsigned int bin_sign,
								t_bin o, t_mem *mem)
{
	o.bin2 = (bin_sign << 26) >> 26;
	o.bin1 = ((bin_sign >> 6) << 26) >> 26;
	o.bin0 = ((bin_sign >> 12) << 28) >> 28;
	final = (o.mask1 >> 16) | o.bin0;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask1 << 16) >> 24) | o.bin1;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask1 << 24) >> 24) | o.bin2;
	write(1, &final, 1);
	++NB_READ;
}

static void			ft_putwchar_iv(unsigned char final, unsigned int bin_sign,
								t_bin o, t_mem *mem)
{
	o.bin3 = (bin_sign << 26) >> 26;
	o.bin2 = ((bin_sign >> 6) << 26) >> 26;
	o.bin1 = ((bin_sign >> 12) << 26) >> 26;
	o.bin0 = ((bin_sign >> 18) << 29) >> 29;
	final = (o.mask2 >> 24) | o.bin0;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask2 << 8) >> 24) | o.bin1;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask2 << 16) >> 24) | o.bin2;
	write(1, &final, 1);
	++NB_READ;
	final = ((o.mask2 << 24) >> 24) | o.bin3;
	write(1, &final, 1);
	++NB_READ;
}

/*
**	WRITE A WCHAR
*/

void				ft_putwchar(wchar_t sign, t_mem *mem)
{
	t_bin			o;
	unsigned char	final;
	unsigned int	bin_sign;
	unsigned int	nb_bin_sign;

	final = 0;
	ft_mask(&o);
	bin_sign = sign;
	nb_bin_sign = ft_strlen(ft_itoa_base(sign, 2));
	if (nb_bin_sign <= 7)
	{
		final = sign;
		write(1, &final, 1);
		++NB_READ;
	}
	else if (nb_bin_sign <= 11)
		ft_putwchar_ii(final, bin_sign, o, mem);
	else if (nb_bin_sign <= 16)
		ft_putwchar_iii(final, bin_sign, o, mem);
	else
		ft_putwchar_iv(final, bin_sign, o, mem);
}
