/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:57 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/24 18:09:50 by kboddez          ###   ########.fr       */
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
	return (new_node);
}

/*
**	BROWSE DIRECTORY AND STORE INFOS ON EACH FILE/DIR IN "t_elem *all"
*/
int		ls_storage(t_elem *all)
{
	t_store	store;
	char	*path_tmp;

	path_tmp = ft_strdup(PATH);
	if ((S_DIR = opendir(PATH)) == NULL)
		return (ls_exit(-1));
	while ((RT_DIR = readdir(S_DIR)) != NULL)
	{
		FILE_NAME = malloc(sizeof(FILE_NAME) * ft_strlen(RT_DIR->d_name));
		ft_strcpy(FILE_NAME, RT_DIR->d_name);
//		PATH = ft_strdup(ft_strjoin(path_tmp, FILE_NAME));
// ================================
//	TU AS UN PROBLEME AVEC LES PATH LORS DE LA RECURSIVITE
//	SORS TOI UN PEU LES DOIGTS DU CUL
// ================================
		lstat(PATH, &INFOS);
		if (S_ISDIR(INFOS.st_mode) &&
			ft_strcmp(".", FILE_NAME) && ft_strcmp("..", FILE_NAME))
		{
			PATH = ft_strdup(path_tmp);
			PATH = ft_strjoin(PATH, "/");
			PATH = ft_strjoin(PATH, FILE_NAME);
			IS_DIR = 1;
		}
		else if (S_ISDIR(INFOS.st_mode))
			IS_DIR = 0;
		NEXT = new_node_elem(all);
		all = NEXT;
		PATH = path_tmp;
	}
	return (0);
}
