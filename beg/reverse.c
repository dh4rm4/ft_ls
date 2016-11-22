/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:52:59 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/22 13:37:47 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../v0.1/libft/libft.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

#define bug(x) ft_strendl(x)

typedef struct		s_elem
{
	char			*name;
	struct stat		infos;
	struct s_elem	*first;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_path
{
	char 			*path;
	struct s_path	*next;
	struct s_path	*first;
}					t_path;

int	start(int reverse, const char *path, t_elem *all, struct dirent *rt_dir, t_path *recu);

static t_elem	*newmail(t_elem *all)
{
	t_elem	*new;

	new = malloc(sizeof(*new));
	new->prev = all;
	new->first = all->first;
	new->next = NULL;
	return (new);
}

static t_path	*newmail_path(t_path *recu)
{
	t_path	*new;

	new = malloc(sizeof(*new));
	new->first = recu->first;
	new->next = NULL;
	return (new);
}

static void	print_dir(int reverse, t_elem *all, t_path *recu, struct dirent *rt_dir)
{
	static int i = 0;
	t_path	*new_recu;
	t_elem	*new_all;

	new_recu = malloc(sizeof(*new_recu));
	new_all = malloc(sizeof(*new_all));
	new_all->first = all;
	new_all->next = NULL;
	new_all->prev = NULL;
	new_recu->next = NULL;
	new_recu->path = NULL;
	new_recu->first = new_recu;
	printf("%s\n", recu->path);
	if (!reverse)
	{
		all = all->first;
		while (all->next)
		{
			printf("%s\n", all->name);
			all = all->next;
		}
	}
	else
	{
		all = all->prev;
		while (all)
		{
			printf("%s\n", all->name);
			all = all->prev;
		}
	}
	if (recu != NULL)
	{
		ft_strendl("\n=====================================");
		recu = recu->next;
		start(reverse, recu->path, new_all, rt_dir, new_recu);
		recu = recu->next;
	}
}

static int	storage(const char *path, t_elem *all, struct dirent *rt_dir, t_path *recu)
{
	DIR				*dir;

	if ((dir = opendir(path)) == NULL)
	{
		perror("");
		return (-1);
	}
	while ((rt_dir = readdir(dir)) != NULL)
	{
		all->name = malloc(sizeof(all->name) * ft_strlen(rt_dir->d_name));
		strcpy(all->name, rt_dir->d_name);
		lstat(all->name, &all->infos);
		if (S_ISDIR(all->infos.st_mode) && strcmp(".", all->name)
			&& strcmp("..", all->name))
		{
			recu->next = newmail_path(recu);
			recu = recu->next;
			recu->path = malloc(sizeof(recu->path) * ft_strlen(all->name));
			recu->path = ft_strjoin(path, "/");
			recu->path = ft_strjoin(recu->path, all->name);
			ft_putstr("DIR = ");
			ft_strendl(recu->path);
		}
		all->next = newmail(all);
		all = all->next;
	}
	if (recu->next != NULL)
		recu = recu->next;
	return (0);
}

int	start(int reverse, const char *path, t_elem *all, struct dirent *rt_dir, t_path *recu)
{
	if (lstat(path, &(all->infos)) == -1)
	{
		perror("");
		return (-1);
	}
	if (S_ISDIR(all->infos.st_mode))
	{
		recu->path = malloc(sizeof(recu->path) * ft_strlen(path));
		ft_strncpy((char *)recu->path, path, ft_strlen(path));
		storage(path, all, rt_dir, recu);
/*		while (recu->next)
		{
			ft_strendl(recu->path);
			recu = recu->next;
		}
*/		recu = recu->first;
		print_dir(reverse, all, recu, rt_dir);
	}
	return (0);
}

int			main(int ac, char *av[])
{
	struct dirent	*rt_dir;
	t_elem			*all;
	t_path			*recu;

	all = malloc(sizeof(*all));
	recu = malloc(sizeof(*recu));
	all->first = all;
	all->next = NULL;
	all->prev = NULL;
	recu->next = NULL;
	recu->path = NULL;
	recu->first = recu;
	if (ac > 1)
		return(start(atoi(av[1]), av[2], all, rt_dir, recu));
	return (0);
}
