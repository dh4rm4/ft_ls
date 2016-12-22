/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 10:51:38 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/10 16:42:04 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*now;

	if (alst != NULL && del != NULL)
	{
		now = *alst;
		while (now)
		{
			(*del)(now->content, now->content_size);
			free(now);
			now = now->next;
		}
		*alst = NULL;
	}
}
