/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:35 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/28 12:13:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_SIZE in BITS_// OF THE "FILE / DIR"
*/
char 		*ls_name(char *total, char *name)
{
	char    *rtr;

	rtr = ft_strnew(0);
	rtr = join_with_char(' ', total, name);
	return (rtr);
}

/*
**	PART II OF LS_TIME
*/

static void	ls_time_II(char *rtr, t_tmp_time *stc)
{
	I = 0;
	J = -1;
	while (rtr[I] != ' ')
		++I;
	while (rtr[++I] != ' ' || !ft_isdigit(rtr[I - 1]))
		MONTH_DAY[++J] = rtr[I];
	MONTH_DAY[++J] = '\0';
	J = -1;
	while (rtr[++I] != ' ')
		HOUR[++J] = rtr[I];
	HOUR[J - 2] = '\0';
	J = -1;
	while (rtr[++I])
	{
		YEAR[++J] = rtr[I];
	}
	YEAR[4] = '\0';
}

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_TIME_// OF THE "FILE / DIR"
*/
char 		*ls_time(char *total, struct stat *infos)
{
	char        *rtr;
	t_tmp_time	*stc;

	STC_TMP = localtime(&infos->st_atime);
	rtr = ft_strnew(0);
	strftime(rtr, 420,"%c", STC_TMP);
	STC_NOW = time(NULL);
	ls_time_II(rtr, stc);
	rtr = join_with_char(' ', total, MONTH_DAY);
	if (STC_NOW - infos->st_atime >= 15811200)
		rtr = join_with_char(' ', rtr, YEAR);
	else
		rtr = join_with_char(' ', rtr, HOUR);
	return (rtr);
}

/*
**	STOCK THE INFOS OF OPTION '-l'
*/
void		ls_infos(t_store *store, t_elem *all)
{
	F_FILE = ft_strnew(0);
	F_FILE[0] = '\0';
	F_FILE = ls_permission(INFOS);
	F_FILE = ls_hard_link(F_FILE, &INFOS);
	F_FILE = ls_owner(F_FILE, &INFOS);
	F_FILE = ls_group(F_FILE, &INFOS);
	F_FILE = ls_size(F_FILE, &INFOS);
	F_FILE = ls_time(F_FILE, &INFOS);
	F_FILE = join_with_char(' ', F_FILE, FILE_NAME);
}
