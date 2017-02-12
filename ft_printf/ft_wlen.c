/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:53:50 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/12 10:56:54 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_wlen(wchar_t w)
{
	int	nb_bin;

	nb_bin = ft_strlen(ft_itoa_base(w, 2));
	if (nb_bin <= 7)
		return (1);
	else if (nb_bin <= 11)
		return (2);
	else if (nb_bin <= 16)
		return (3);
	return (4);
}
