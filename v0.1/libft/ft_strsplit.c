/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:54:13 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/21 15:01:16 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ctstr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c)
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static int		ft_lens(char const *s, char c, int i)
{
	int	len;

	len = 1;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		*ft_checkstr(char const *s, char c, int i)
{
	int		i_str;
	char	*str;

	i_str = 0;
	str = (char *)malloc(sizeof(*str) * (ft_lens(s, c, i) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		str[i_str] = s[i];
		i_str++;
		i++;
	}
	str[i_str] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i_s;
	char	**tab;

	if (s != NULL)
	{
		if (!(tab = (char **)malloc(sizeof(tab) * (ft_ctstr(s, c) + 1))))
			return (NULL);
		i = 0;
		i_s = 0;
		while (i < ft_ctstr(s, c) && s[i_s] != '\0')
		{
			while (s[i_s] == c)
				i_s++;
			tab[i] = ft_checkstr(s, c, i_s);
			if (tab[i] == NULL)
				return (NULL);
			while (s[i_s] != c && s[i_s] != '\0')
				i_s++;
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
