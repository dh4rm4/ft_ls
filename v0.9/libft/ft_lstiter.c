/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 11:22:38 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/06 12:57:55 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*now;

	if (lst)
	{
		now = lst;
		while (now != NULL)
		{
			(*f)(now);
			now = now->next;
		}
	}
}
