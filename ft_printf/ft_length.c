/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 13:25:23 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:45:37 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	FIND THE LENGTH OF WCHAR STRINGS
*/

static int		ft_wlength(t_mem *mem)
{
	int	i;
	int	len;
	int	nb_bin;

	len = 0;
	i = 0;
	while (WOUT[i])
	{
		nb_bin = ft_strlen(ft_itoa_base(WOUT[i], 2));
		if (nb_bin <= 7)
			++len;
		else if (nb_bin <= 11)
			len += 2;
		else if (nb_bin <= 16)
			len += 3;
		else
			len += 4;
		++i;
	}
	return (len);
}

/*
**	FIND THE LENGTH OF STRINGS
*/

static size_t	ft_strlen_type(char type, const char *s, t_mem *mem)
{
	size_t	len;

	if (NB_PREC <= 0 && *OUT == '0' && PREC_CHECK > 0 &&
		(type == 'o' || type == 'O' || type == 'x' || type == 'X'
		|| type == 'u' || type == 'U'))
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/*
**	FIND THE LENGTH
*/

int				ft_length(char type, t_mem *mem, int mod)
{
	if (type == 'S' && mod == 0)
		return (ft_wlength(mem));
	else if ((type == 's' || type == 'x' || type == 'X' ||
		type == 'o' || type == 'O' || type == 'u' || type == 'p') && mod == 0)
		return (ft_strlen_type(type, OUT, mem));
	else if ((type == 's' || type == 'S' || type == 'x' || type == 'X' ||
			type == 'o' || type == 'O') && mod == 1)
		return (0);
	else if (type == 'c' || type == 'C')
		return (1);
	else
		return (printf_nbr_length(D, mem));
}
