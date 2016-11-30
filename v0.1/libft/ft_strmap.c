/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:44:14 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/21 14:53:49 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	str = NULL;
	if (s != NULL && f != NULL)
	{
		str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
