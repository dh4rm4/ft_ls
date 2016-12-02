/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:39:23 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/02 16:18:03 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	FILL PERM (= all->perm)
**  WITH THE \\_PERMISSION_// OF THE "FILE / DIR"
*/
void	ls_permission(t_stat infos, t_elem *all)
{
// GERER LES STICKY BITS
// GERER LES "SUID"
//	================================================
// GERER LE CAS POUR TOUS LES TYPES DE FICHIERS
	PERM[0] = (S_ISDIR(infos.st_mode)) ? 'd' : '-';
//	================================================
	PERM[1] = (infos.st_mode & S_IRUSR) ? 'r' : '-';
	PERM[2] = (infos.st_mode & S_IWUSR) ? 'w' : '-';
	PERM[3] = (infos.st_mode & S_IXUSR) ? 'x' : '-';
	PERM[4] = (infos.st_mode & S_IRGRP) ? 'r' : '-';
	PERM[5] = (infos.st_mode & S_IWGRP) ? 'w' : '-';
	PERM[6] = (infos.st_mode & S_IXGRP) ? 'x' : '-';
	PERM[7] = (infos.st_mode & S_IROTH) ? 'r' : '-';
	PERM[8] = (infos.st_mode & S_IWOTH) ? 'w' : '-';
	PERM[9] = (infos.st_mode & S_IXOTH) ? 'x' : '-';
	PERM[10] = '\0';
	if (listxattr(PATH, NULL, 0, XATTR_NOFOLLOW) > 0)
		PERM[10] = '@';
	else if (acl_get_file(PATH, ACL_TYPE_EXTENDED))
		PERM[10] = '+';
	PERM[11] = '\0';
}

/*
**	FILL OWNER (= all->owner)
**  WITH THE \\_OWNER_// OF THE "FILE / DIR"
*/
void	ls_owner(t_stat *infos, t_elem *all)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(infos->st_uid)))
		OWNER = ft_strdup(pwd->pw_name);
	else
		OWNER = pwd->pw_name;
}

/*
**	FILL GROUP (= all->group)
**  WITH THE \\_GROUP_// OF THE "FILE / DIR"
*/
void	ls_group(t_stat *infos, t_elem *all)
{
	struct group    *grp;

	if ((grp  = getgrgid(infos->st_gid)))
		GROUP = ft_strdup(grp->gr_name);
	else
		GROUP = ft_itoa(infos->st_gid);
}
