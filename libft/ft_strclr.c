/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:12:11 by kboddez           #+#    #+#             */
/*   Updated: 2016/08/15 09:33:05 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strclr(char *s)
{
	int	index;
	int	s_len;

	if (s != NULL)
	{
		index = 0;
		s_len = ft_strlen(s);
		while (index < s_len)
		{
			s[index] = '\0';
			index++;
		}
	}
}
