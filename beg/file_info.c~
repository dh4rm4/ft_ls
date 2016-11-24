/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:52:59 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/21 16:20:14 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../v0.1/libft/libft.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

static int	start(const char *restrict path)
{
	struct stat		infos;
	struct dirent	*rt_dir;
	char			*perm;
	int				i;
	DIR				*dir;

	i = 0;
	perm = ft_strnew(10);
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
			i = 0;
			lstat(rt_dir->d_name, &infos);
			perm[i] = (S_ISDIR(infos.st_mode)) ? 'd' : '-';
			perm[++i] = (infos.st_mode & S_IRUSR) ? 'r' : '-';
			perm[++i] = (infos.st_mode & S_IWUSR) ? 'w' : '-';
			perm[++i] = (infos.st_mode & S_IXUSR) ? 'x' : '-';
			perm[++i] = (infos.st_mode & S_IRGRP) ? 'r' : '-';
			perm[++i] = (infos.st_mode & S_IWGRP) ? 'w' : '-';
			perm[++i] = (infos.st_mode & S_IXGRP) ? 'x' : '-';
			perm[++i] = (infos.st_mode & S_IROTH) ? 'r' : '-';
			perm[++i] = (infos.st_mode & S_IWOTH) ? 'w' : '-';
			perm[++i] = (infos.st_mode & S_IXOTH) ? 'x' : '-';
			printf("%s - %s\n", perm, rt_dir->d_name);
		}
	}
	else
	{
		perm[i] = (S_ISDIR(infos.st_mode)) ? 'd' : '-';
		perm[++i] = (infos.st_mode & S_IRUSR) ? 'r' : '-';
		perm[++i] = (infos.st_mode & S_IWUSR) ? 'w' : '-';
		perm[++i] = (infos.st_mode & S_IXUSR) ? 'x' : '-';
		perm[++i] = (infos.st_mode & S_IRGRP) ? 'r' : '-';
		perm[++i] = (infos.st_mode & S_IWGRP) ? 'w' : '-';
		perm[++i] = (infos.st_mode & S_IXGRP) ? 'x' : '-';
		perm[++i] = (infos.st_mode & S_IROTH) ? 'r' : '-';
		perm[++i] = (infos.st_mode & S_IWOTH) ? 'w' : '-';
		perm[++i] = (infos.st_mode & S_IXOTH) ? 'x' : '-';
		printf("%s - %s\n", perm, path);
	}
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac > 1)
		return(start(av[1]));
	return (0);
}
