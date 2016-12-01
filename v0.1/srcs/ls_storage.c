/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/01 13:13:16 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	CREATE AND RETURN NEW NODE FOR LINKED LIST "t_elem *all"
*/
static t_elem	*new_node_elem(t_elem *all)
{
	t_elem	*new_node;

	new_node = malloc(sizeof(*new_node));
	new_node->first = FIRST;
	new_node->prev = all;
	new_node->next = NULL;
	new_node->old_path = ft_strdup(OLD_PATH);
	new_node->path = OLD_PATH;
	return (new_node);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH DIR IN "t_elem *all"
*/
int		ls_storage_dir(t_elem *all)
{
	t_store	store;
	t_group	*grp;
	t_stat	infos;

	IS_DIR = 1;
	PATH = ft_strdup(OLD_PATH);
	if ((S_DIR = opendir(PATH)) == NULL)
		return (ls_exit(-1));
	while ((RT_DIR = readdir(S_DIR)) != NULL)
	{
		FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(RT_DIR->d_name));
		ft_strcpy(FILE_NAME, RT_DIR->d_name);
		PATH = join_with_char('/', PATH, FILE_NAME);
		if (lstat(PATH, &infos) == -1)
			return (ls_exit(-1));
		ls_infos(&store, infos, all);
		if (S_ISDIR(infos.st_mode) &&
			ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
			IS_DIR = 1;
		else
			IS_DIR = 0;
		NEXT = new_node_elem(all);
		all = NEXT;
	}
	if (closedir(S_DIR) == -1)
		return (ls_exit(-1));
	return (0);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH DIR IN "t_elem *all"
*/
int		ls_storage_file(t_elem *all)
{
	t_store	store;
	t_stat	infos;

	IS_DIR = 0;
	PATH = ft_strdup(OLD_PATH);
	FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(PATH));
	ft_strcpy(FILE_NAME, PATH);
	lstat(FILE_NAME, &infos);
	ls_infos(&store, infos, all);
	return (0);
}
