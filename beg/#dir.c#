/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:19:59 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/21 12:44:34 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../v0.1/libft/libft.h"
#include <dirent.h>

static int	start(char *directory)
{
	DIR				*dir;
	struct dirent	*rtr;

	if ((dir = opendir(directory)) == NULL)
		return (-1);
	while ((rtr = readdir(dir)) != NULL)
		printf("%s\n", rtr->d_name);
	return (0);
}

int			main(int argc, char *argv[])
{
	if (argc > 1)
		start(argv[1]);
	return (0);
}
