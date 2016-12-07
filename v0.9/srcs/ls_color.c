/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:39:34 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 13:45:22 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ls_color(T_STAT stat)
{
    if (S_ISDIR(stat.st_mode))
		ft_printf("%s", BLUE);
	else if (S_ISLNK(stat.st_mode))
		ft_printf("%s", PINK);
	else if (stat.st_mode & S_IXUSR)
		ft_printf("%s", RED);
	else
		ft_printf("%s", WHITE);
}
