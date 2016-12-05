/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:44:14 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/18 15:42:00 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = NULL;
	if (s != NULL && f != NULL)
	{
		if (!(str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
