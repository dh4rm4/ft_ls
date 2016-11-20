/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:26:21 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/15 15:04:56 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(*s1) * (ft_strlen(dst) + 1));
	s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(src) + 1));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (s2 && n)
	{
		*(s1++) = *(s2++);
		n--;
	}
	return (dst);
}
