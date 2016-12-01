/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_with_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:17:23 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/30 16:00:18 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	CREATE A FRESH STRING 'str' AND CONCATENATE 's1' & 's2' WITH THE 'c'
**	BETWEEN THEM IN IT, AND RETURN 'str'
*/
char			*join_with_char(char c, char const *s1, char const *s2)
{
	int		i_str;
	int		i_s2;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str)
	* (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i_str = 0;
	i_s2 = 0;
	while (s1[i_str] != '\0')
	{
		str[i_str] = s1[i_str];
		i_str++;
	}
	str[i_str++] = c;
	while (s2[i_s2] != '\0')
	{
		str[i_str] = s2[i_s2];
		i_str++;
		i_s2++;
	}
	str[i_str] = '\0';
	return (str);
}
