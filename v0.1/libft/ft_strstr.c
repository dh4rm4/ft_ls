/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:15:56 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/03 17:45:11 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		s1_i;
	int		s2_i;
	int		mem;
	char	*ptr;

	s1_i = 0;
	s2_i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[s1_i] != '\0')
	{
		ptr = (char *)&s1[s1_i];
		mem = s1_i;
		while (s1[s1_i] == s2[s2_i] && s1[s1_i] && s2[s2_i])
		{
			s1_i++;
			s2_i++;
		}
		if (s2[s2_i] == '\0')
			return (ptr);
		s1_i = mem;
		s1_i++;
		s2_i = 0;
	}
	return (NULL);
}
