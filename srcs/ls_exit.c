/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:09:36 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/15 14:47:38 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int	ls_exit(int rtr, char *path)
{
	ft_printf("ft_ls: %s: ", path);
	perror("");
	return (rtr);
}
