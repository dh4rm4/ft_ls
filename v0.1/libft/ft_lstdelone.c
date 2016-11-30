/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 10:50:58 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/11 15:54:54 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*now;

	if (*alst)
	{
		now = *alst;
		(*del)(now->content, now->content_size);
		free(now);
		now->next = NULL;
		*alst = NULL;
	}
}
