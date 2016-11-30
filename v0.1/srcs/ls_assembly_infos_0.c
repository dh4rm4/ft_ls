/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:23 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/30 15:11:05 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_PERMISSION_// OF THE "FILE / DIR"
**  CASE0(x) : total = ft_strjoin(total, x)
**  CASE1    : total = ft_strjoin(total, "-")
*/
char *ls_permission(struct stat infos)
{
	char            *total;

	total = ft_strnew(0);
	(S_ISDIR(infos.st_mode)) ? CASE0("d") : CASE1;
	(infos.st_mode & S_IRUSR) ? CASE0("r") : CASE1;
	(infos.st_mode & S_IWUSR) ? CASE0("w") : CASE1;
	(infos.st_mode & S_IXUSR) ? CASE0("x") : CASE1;
	(infos.st_mode & S_IRGRP) ? CASE0("r") : CASE1;
	(infos.st_mode & S_IWGRP) ? CASE0("w") : CASE1;
	(infos.st_mode & S_IXGRP) ? CASE0("x") : CASE1;
	(infos.st_mode & S_IROTH) ? CASE0("r") : CASE1;
	(infos.st_mode & S_IWOTH) ? CASE0("w") : CASE1;
	(infos.st_mode & S_IXOTH) ? CASE0("x") : CASE1;
	return (total);
}

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_HARD LINK_// OF THE "FILE / DIR"
*/
char *ls_hard_link(char *total, struct stat *infos)
{
	char    *rtr;

	rtr = ft_strnew(0);
	rtr = join_with_char(' ', total, ft_itoa(infos->st_nlink));
	return (rtr);
}

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_OWNER_// OF THE "FILE / DIR"
*/
char *ls_owner(char *total, struct stat *infos)
{
	struct passwd   *pwd;
	char    *rtr;

	rtr = ft_strnew(0);
	pwd = getpwuid(infos->st_uid);
	rtr = join_with_char(' ', total, pwd->pw_name);
	return (rtr);
}

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_GROUP_// OF THE "FILE / DIR"
*/
char *ls_group(char *total, struct stat *infos)
{
	struct group    *grp;
	char    *rtr;

	rtr = ft_strnew(0);
	grp = getgrgid(infos->st_gid);
	rtr = join_with_char(' ', total, grp->gr_name);
	return (rtr);
}

/*
**  CONCATENATE AND RETURN A STRING
**  WITH THE \\_SIZE in BITS_// OF THE "FILE / DIR"
*/
char *ls_size(char *total, struct stat *infos)
{
	char    *rtr;

	rtr = ft_strnew(0);
	rtr = join_with_char(' ', total, ft_itoa(infos->st_size));
	return (rtr);
}
