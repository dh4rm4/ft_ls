/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:59:12 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/07 13:01:07 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s1_i;
	size_t	s2_i;
	size_t	mem;
	char	*ptr;

	s1_i = 0;
	s2_i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[s1_i] != '\0' && s1_i < n)
	{
		ptr = ((char *)&s1[s1_i]);
		mem = s1_i;
		while (s1[s1_i] == s2[s2_i] && s1[s1_i] && s2[s2_i] && s1_i < n)
		{
			s1_i++;
			s2_i++;
		}
		if (s2[s2_i] == '\0')
			return (ptr);
		s1_i = mem;
		s2_i = 0;
		s1_i++;
	}
	return (NULL);
}
