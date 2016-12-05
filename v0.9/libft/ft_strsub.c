/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:30:03 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/21 14:32:40 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*ptr;

	if (s != NULL && start <= ft_strlen(s))
	{
		index = 0;
		ptr = (char *)malloc(sizeof(*ptr) * (len + 1));
		if (ptr != NULL)
		{
			while (s[start] != '\0' && index < len)
			{
				ptr[index] = s[start];
				index++;
				start++;
			}
			ptr[index] = '\0';
		}
		if (len == 0)
			ptr[index] = '\0';
		return (ptr);
	}
	return (NULL);
}
