/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:39:00 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/25 10:52:51 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  CREATE A FRESH STRING 'str' AND CONCATENATE 's1' & 's2'
**  IN IT, AND RETURN 'str'
*/
char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i_str;
	int		i_s2;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str)
	* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i_str = 0;
	i_s2 = 0;
	while (s1[i_str] != '\0')
	{
		str[i_str] = s1[i_str];
		i_str++;
	}
	while (s2[i_s2] != '\0')
	{
		str[i_str] = s2[i_s2];
		i_str++;
		i_s2++;
	}
	str[i_str] = '\0';
	return (str);
}
