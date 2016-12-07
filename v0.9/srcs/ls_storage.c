/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/06 14:08:08 by kboddez          ###   ########.fr       */
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
	new_node->next = NULL;
	new_node->prev = all;
	new_node->file_name = NULL;
	new_node->old_path = ft_strdup(OLD_PATH);
	new_node->path = OLD_PATH;
	return (new_node);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH DIR IN "t_elem *all"
*/

int				ls_storage_dir(int ops[11], t_elem *all)
{
	t_store	store;
	T_STAT	infos;
	T_GROUP	*grp;
	T_PWD	*pwd;

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
		ls_infos(ops, &store, &infos, all);
		IS_DIR = (S_ISDIR(infos.st_mode)) ? 1 : 0;
		NEXT = new_node_elem(all);
		all = NEXT;
	}
	closedir(S_DIR);
	return (0);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH DIR IN "t_elem *all"
*/

int				ls_storage_file(int ops[11], t_elem *all)
{
	t_store	store;
	T_STAT	infos;

	PATH = ft_strdup(OLD_PATH);
	FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(PATH));
	ft_strcpy(FILE_NAME, PATH);
	if (lstat(FILE_NAME, &infos) == -1)
		return (ls_exit(-1));
	IS_DIR = (S_ISDIR(infos.st_mode)) ? 1 : 0;
	ls_infos(ops, &store, &infos, all);
	return (0);
}
