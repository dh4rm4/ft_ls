/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 10:11:32 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
**	CREATE AND RETURN NEW NODE FOR LINKED LIST "t_path *recur"
*/
static t_path	*new_node_path(t_path *recur)
{
	t_path	*new_node;

	new_node = malloc(sizeof(*new_node));
	new_node->first = RFIRST;
	new_node->next = NULL;
	new_node->prev = recur;
	return (new_node);
}

/*
**	CREATE AND RETURN NEW NODE FOR LINKED LIST "t_elem *all"
*/
static t_elem	*new_node_elem(t_elem *all)
{
	t_elem	*new_node;

	new_node = malloc(sizeof(*new_node));
	new_node->first = AFIRST;
	new_node->prev = all;
	new_node->next = NULL;
	return (new_node);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH FILE/DIR IN "t_elem *all"
*/
int		ls_storage(t_dirent *rtr_dir, t_elem *all, t_path *recur)
{
	DIR		*dir;
	char	*tmp_path;

	tmp_path = ft_strnew(ft_strlen(RPATH));
	ft_strcpy(tmp_path, RPATH);
	if ((dir = opendir(RPATH)) == NULL)
		return (ls_exit(-1));
	while ((rtr_dir = readdir(dir)) != NULL)
	{
		FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(rtr_dir->d_name));
		ft_strcpy(FILE_NAME, rtr_dir->d_name);
		lstat(FILE_NAME, &AINFOS);
		if (S_ISDIR(AINFOS.st_mode) &&
			ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{

			RNEXT = new_node_path(recur);
			recur = RNEXT;
			RPATH = malloc(sizeof(*RPATH) * ft_strlen(FILE_NAME));
			RPATH = ft_strjoin(tmp_path, "/");
			RPATH = ft_strjoin(RPATH, FILE_NAME);
		}
		else if (S_ISDIR(AINFOS.st_mode))
			printf("TEST_FAIL = %s\n", FILE_NAME);
		ANEXT = new_node_elem(all);
		all = ANEXT;
	}
	recur = RFIRST;
	recur = RNEXT;
	return (0);
}