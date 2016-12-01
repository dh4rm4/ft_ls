/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:35 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/01 13:13:37 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	FILL TIME (= all->time)
**  WITH THE \\_TIME_// OF THE "FILE / DIR"
*/
void		ls_time(t_stat infos, t_elem *all)
{
	char		*rtr;
	size_t		i;
	struct tm	*stc;

	i = -1;
	rtr = ft_strnew(0);
	stc = localtime(&infos.st_atime);
	strftime(rtr, 420,"%c", stc);
	rtr += 4;
	while (ft_isdigit(*(rtr - 1)) != 1)
		TIME[++i] = *(rtr++);
	TIME[++i] = '\0';
}

/*
**	STOCK THE INFOS OF OPTION '-l'
*/
void		ls_infos(t_store *store, t_stat infos, t_elem *all)
{
	ls_permission(infos, all);
	HARD_LINK = ft_itoa(infos.st_nlink);
	ls_owner(infos, all);
	ls_group(infos, all);
	SIZE = ft_itoa(infos.st_size);
	ls_time(infos, all);
}
