/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:23:46 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/11 12:32:45 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[index] == s2[index] && index < n &&
				s1[index] != '\0' && s2[index] != '\0')
		{
			if ((s1[index + 1] == '\0' && s2[index + 1] == '\0')
				|| (index + 1) == n)
				return (1);
			index++;
		}
		if ((s1[index] == '\0' && s2[index] == '\0') || n == 0)
			return (1);
	}
	return (0);
}
