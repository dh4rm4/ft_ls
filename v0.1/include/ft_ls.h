/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/22 15:00:13 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_
# define _FT_LS_

/*
**	INCLUDES
*/
# include "../libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>

/*
**	MACROS
*/
# define bug(x) ft_strendl(x)

# define t_dirent struct dirent

# define FILE_NAME all->file_name
# define AINFOS all->infos
# define AFIRST all->first
# define ANEXT all->next
# define APREV all->prev

# define RPATH recur->path
# define RNEXT recur->next
# define RFIRST recur->first
# define RPREV recur->prev

/*
**	LINKED LIST FOR DIR/FILES
*/
typedef struct		s_elem
{
	char			*file_name;
	struct stat		infos;
	struct s_elem	*first;
	struct s_elem	*next;
	struct s_elem	*prev;

}					t_elem;

/*
**	LINKED LIST FOR NEW DIRECTORY FIND (RECURSIVITY)
*/
typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
	struct s_path	*first;
	struct s_path	*prev;
}					t_path;

int					ls_start(const char *path);

int					ls_storage(t_dirent *rtr_dir, t_elem *all, t_path *recur);
int					ls_print(t_dirent *rtr_dir, t_elem *all, t_path *recur);

int					ls_exit(int rtr);

#endif
