/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:27:16 by kboddez           #+#    #+#             */
/*   Updated: 2015/12/14 10:55:36 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstnew;
	t_list	*tp;
	t_list	*start;

	lstnew = NULL;
	while (lst)
	{
		if (!(tp = (t_list *)malloc(sizeof(*tp))))
			return (NULL);
		tp = f(lst);
		if (!lstnew)
		{
			lstnew = tp;
			start = lstnew;
			lstnew->next = NULL;
		}
		else
		{
			lstnew->next = tp;
			tp->next = NULL;
			lstnew = lstnew->next;
		}
		lst = lst->next;
	}
	return (start);
}
