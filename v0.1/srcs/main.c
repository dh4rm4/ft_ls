/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:29:44 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/20 13:33:19 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int	main(int argc, char *argv)
{
	t_vog	rmb;

	if (argc > 2 || !ft_strcmp("ll" , argv[1]) || !ft_strcmp("la", argv[1]))
		ft_arg(argc, argv, &rmb);
	else
		start(&rmb);
	return (0);
}
