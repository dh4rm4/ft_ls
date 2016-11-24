/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:52:59 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 12:30:40 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../v0.1/libft/libft.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

# define CASE0(x) (perm = ft_strjoin(perm, x))
# define CASE1 (perm = ft_strjoin(perm, "-"))

/*
**	CONCATENATE AND RETURN A STRING
**	WITH THE \\_PERMISSION_// OF THE "FILE / DIR"
**	CASE0(x) : perm = ft_strjoin(perm, x)
**	CASE1    : perm = ft_strjoin(perm, "-")
*/
static char	*ls_permission(struct stat infos)
{
	char			*perm;

	perm = ft_strnew(0);
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
	return (perm);
}

/*
**	CONCATENATE AND RETURN A STRING
**	WITH THE \\_HARD LINK_// OF THE "FILE / DIR"
*/
static char	*ls_hard_link(char *perm, struct stat *infos)
{
	char	*rtr;

	rtr = ft_strnew(0);
	rtr = ft_strjoin(perm, " ");
	rtr = ft_strjoin(rtr, ft_itoa(infos->st_nlink));
	rtr = ft_strjoin(rtr, " ");
	return (rtr);
}

/*
**	CONCATENATE AND RETURN A STRING
**	WITH THE \\_OWNER_// OF THE "FILE / DIR"
*/
static char	*ls_owner(char *perm, struct stat *infos)
{
	struct passwd	*pwd;
	char	*rtr;

	rtr = ft_strnew(0);
	rtr = ft_strjoin(perm, " ");
	pwd = getpwuid(infos->st_uid);
	rtr = ft_strjoin(rtr, pwd->pw_name);
	rtr = ft_strjoin(rtr, " ");
	return (rtr);
}

/*
**	CONCATENATE AND RETURN A STRING
**	WITH THE \\_GROUP_// OF THE "FILE / DIR"
*/
static char	*ls_group(char *perm, struct stat *infos)
{
	struct group	*grp;
	char	*rtr;

	rtr = ft_strnew(0);
	rtr = ft_strjoin(perm, " ");
	grp = getgrgid(infos->st_gid);
	rtr = ft_strjoin(rtr, grp->gr_name);
	rtr = ft_strjoin(rtr, " ");
	return (rtr);
}

/*
**	CONCATENATE AND RETURN A STRING
**	WITH THE \\_SIZE in BITS_// OF THE "FILE / DIR"
*/
static char	*ls_size(char *perm, struct stat *infos)
{
	char	*rtr;

	printf("%lld\n", infos->st_size);
}


static int	start(const char *restrict path)
{
	struct stat		infos;
	struct dirent	*rt_dir;
	char			*perm;
	DIR				*dir;

	perm = ft_strnew(1);
	perm[0] = '\0';
	if (lstat(path, &infos) == -1)
	{
		perror("");
		return (-1);
	}
	if (S_ISDIR(infos.st_mode))
	{
		if ((dir = opendir(path)) == NULL)
		{
			perror("");
			return (-1);
		}
		while ((rt_dir = readdir(dir)) != NULL)
		{
			lstat(rt_dir->d_name, &infos);
			perm = ls_permission(infos);
			perm = ls_hard_link(perm, &infos);
			perm = ls_owner(perm, &infos);
			perm = ls_group(perm, &infos);
			perm = ls_size(perm, &infos);
			printf("%s - %s\n", perm, rt_dir->d_name);
		}
	}
	else
	{
		perm = ls_permission(infos);
		perm = ls_hard_link(perm, &infos);
		perm = ls_owner(perm, &infos);
		perm = ls_group(perm, &infos);
		perm = ls_size(perm, &infos);
		printf("%s%s\n", perm, path);
	}
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac > 1)
		return(start(av[1]));
	return (0);
}
