/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:21:38 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/21 14:39:13 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trimlen(const char *s)
{
	int	index;
	int	len;

	len = 0;
	index = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	while (s[index] != '\0')
	{
		len++;
		index++;
	}
	while ((s[index - 1] == ' ' || s[index - 1] == '\n'
			|| s[index - 1] == '\t') && len != 0)
	{
		index--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	int		index;
	int		i_s;
	char	*cpy;

	cpy = 0;
	if (s != NULL)
	{
		index = 0;
		i_s = 0;
		if (!(cpy = (char *)malloc(sizeof(*cpy) * (ft_trimlen(s) + 1))))
			return (cpy);
		while (s[i_s] == ' ' || s[i_s] == '\n' || s[i_s] == '\t')
			i_s++;
		while (index < (ft_trimlen(s)))
		{
			cpy[index] = s[i_s];
			index++;
			i_s++;
		}
		cpy[index] = '\0';
		return (cpy);
	}
	return (NULL);
}
