/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:22:38 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/15 15:09:58 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (n)
	{
		str = (unsigned char *)s;
		while (str && n)
		{
			if (*str == (unsigned char)c)
				return ((void *)str);
			str++;
			n--;
		}
	}
	if ((unsigned char)c == '\0' && *str == '\0' && n)
		return ((void *)str);
	return (NULL);
}
