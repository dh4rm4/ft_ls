/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 09:32:28 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/19 11:05:13 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//#define FORMAT "%"
//#define FORMAT "%%"
//#define FORMAT "%%%"
//#define FORMAT "%%%%"
//#define FORMAT "%%%%%%%%%%%%%%%%%%"
//#define FORMAT "% %"
//#define FORMAT "%         %"
#define FORMAT "  %td",420
//#define FORMAT "  %l",420
//#define FORMAT "  %%"
//#define FORMAT "    %%%%%%%%%%%"
//#define FORMAT "%w%"
//#define FORMAT "%",0
//#define FORMAT "%%",0
//#define FORMAT "%%%",0
//#define FORMAT "%%%%",0
//#define FORMAT "%%%%%%%%%%%%%%%%%%",0
//#define FORMAT "% %",0
//#define FORMAT "%         %",0
//#define FORMAT "  %",0
//#define FORMAT "  %%",0
//#define FORMAT "    %%%%%%%%%%%",0
//#define FORMAT "%w%",0
//#define FORMAT
//#define FORMAT
//#define FORMAT

int	main(int ac, char *av[])
{
	int 	ft;
	int		pas_ft;

	ft_printf("ft_printf :");
	ft = ft_printf(FORMAT);
	ft_printf("\n");

	ft_printf("printf    :");
	pas_ft = printf(FORMAT);
	printf("\n\nft     = %d\npas_ft = %d\n", ft, pas_ft);
	return (0);
}
