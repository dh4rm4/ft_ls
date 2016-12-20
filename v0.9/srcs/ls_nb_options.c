/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_nb_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:49:20 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/20 14:05:20 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**  RETURN NBR OPTION PASSED IN ARG
*/

int	ls_nb_options(int ops[11])
{
	int	rtr;

	rtr = OP_L;
	rtr += OP_R;
	rtr += OP_A;
	rtr += OP_RR;
	rtr += OP_T;
	rtr += OP_AA;
	rtr += OP_D;
	return (++rtr);
}
