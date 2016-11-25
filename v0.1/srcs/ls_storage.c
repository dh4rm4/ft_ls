/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/25 10:29:40 by kboddez          ###   ########.fr       */
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
//	new_node->old_path = ft_strjoin(new_node->old_path, FILE_NAME);
	return (new_node);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH FILE/DIR IN "t_elem *all"
*/
int		ls_storage(t_elem *all)
{
	t_store	store;

	PATH = ft_strdup(OLD_PATH);
	if ((S_DIR = opendir(PATH)) == NULL)
		return (ls_exit(-1));
	while ((RT_DIR = readdir(S_DIR)) != NULL)
	{
		FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(RT_DIR->d_name));
		ft_strcpy(FILE_NAME, RT_DIR->d_name);
		PATH = ft_strjoin(PATH, "/");
		PATH = ft_strjoin(PATH, FILE_NAME);
		lstat(PATH, &INFOS);
		if (S_ISDIR(INFOS.st_mode) &&
			ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
			IS_DIR = 1;
		else if (S_ISDIR(INFOS.st_mode))
			IS_DIR = 0;
		NEXT = new_node_elem(all);
		all = NEXT;
	}
	return (0);
}
