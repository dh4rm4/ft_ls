/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:42:04 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/14 15:36:32 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	if (src[index] == '\0' && index < len)
		while (index < len)
		{
			dst[index] = '\0';
			index++;
		}
	return (dst);
}
