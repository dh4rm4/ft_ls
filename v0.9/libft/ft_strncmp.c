/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:43:44 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/14 15:37:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && n > 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
		n--;
	}
	if (s1[i] != s2[i] && n > 0)
		return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
	return (0);
}
