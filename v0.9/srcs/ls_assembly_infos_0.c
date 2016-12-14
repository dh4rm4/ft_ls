/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_assembly_infos_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:20:24 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/14 09:00:58 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	FIND THE TYPE OF FILE AND RETURN
**	THE LETTER FOR THE PERMISSION
*/

static char	ls_file_type(mode_t file_type)
{
	if (S_ISBLK(file_type))
		return ('b');
	if (S_ISCHR(file_type))
		return ('c');
	if (S_ISDIR(file_type))
		return ('d');
	if (S_ISLNK(file_type))
		return ('l');
	if (S_ISSOCK(file_type))
		return ('s');
	if (S_ISFIFO(file_type))
		return ('p');
	return ('-');
}

/*
**	FILL PERM (= all->perm)
**  WITH THE \\_PERMISSION_// OF THE "FILE / DIR"
*/

void		ls_permission(T_STAT infos, t_elem *all)
{
	PERM[0] = ls_file_type(infos.st_mode);
	PERM[1] = (infos.st_mode & S_IRUSR) ? 'r' : '-';
	PERM[2] = (infos.st_mode & S_IWUSR) ? 'w' : '-';
	if (infos.st_mode & S_IXUSR)
		PERM[3] = (infos.st_mode & S_ISUID) ? 's' : 'x';
	else
		PERM[3] = (infos.st_mode & S_ISUID) ? 'S' : '-';
//	PERM[3] = (infos.st_mode & S_IXUSR) ? 'x' : '-';
	PERM[4] = (infos.st_mode & S_IRGRP) ? 'r' : '-';
	PERM[5] = (infos.st_mode & S_IWGRP) ? 'w' : '-';
	if (infos.st_mode & S_IXGRP)
		PERM[6] = (infos.st_mode & S_ISGID) ? 's' : 'x';
	else
		PERM[6] = (infos.st_mode & S_ISGID) ? 'S' : '-';
//	PERM[6] = (infos.st_mode & S_IXGRP) ? 'x' : '-';
	PERM[7] = (infos.st_mode & S_IROTH) ? 'r' : '-';
	PERM[8] = (infos.st_mode & S_IWOTH) ? 'w' : '-';
	if (infos.st_mode & S_IXOTH)
		PERM[9] = (infos.st_mode & S_ISVTX) ? 't' : 'x';
	else
		PERM[9] = (infos.st_mode & S_ISVTX) ? 'T' : '-';
//	PERM[9] = (infos.st_mode & S_IXOTH) ? 'x' : '-';
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

void		ls_owner(T_STAT *infos, t_elem *all)
{
	T_PWD	*pwd;

	if ((pwd = getpwuid(infos->st_uid)))
		OWNER = ft_strdup(pwd->pw_name);
	else
		OWNER = pwd->pw_name;
}

/*
**	FILL GROUP (= all->group)
**  WITH THE \\_GROUP_// OF THE "FILE / DIR"
*/

void		ls_group(T_STAT *infos, t_elem *all)
{
	T_GROUP	*grp;

	if ((grp = getgrgid(infos->st_gid)))
		GROUP = ft_strdup(grp->gr_name);
	else
		GROUP = ft_itoa(infos->st_gid);
}
