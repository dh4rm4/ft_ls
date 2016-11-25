/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/25 09:53:05 by kboddez          ###   ########.fr       */
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
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

/*
**	MACROS TYPE
*/
# define bug(x) ft_strendl(x)
# define t_pwd struct passwd
# define t_group struct group
# define t_dirent struct dirent

/*
**	STORAGE STRUCT MACROS
*/
# define S_DIR store.dir
# define RT_DIR store.rt_dir
# define PWD store.pwd
# define GRP store.pwd

/*
**	LINKED LIST MACROS
*/
# define FILE_NAME all->file_name
# define PATH all->path
# define OLD_PATH all->old_path
# define IS_DIR all->is_dir
# define INFOS all->infos
# define FIRST all->first
# define NEXT all->next
# define PREV all->prev
# define RECUR all->recur

/*
**	STRUCT FOR INFOS STORAGE
*/
typedef struct		s_store
{
    DIR				*dir;
	struct dirent	*rt_dir;
	struct passwd	*pwd;
	struct group	*grp;
}					t_store;

/*
**	LINKED LIST FOR DIR/FILES
*/
typedef struct		s_elem
{
	char			*file_name;
	char			*path;
	char			*old_path;
	size_t			is_dir;

	struct stat		infos;
	struct s_elem	*first;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*last;
	struct s_elem	*recur;

}					t_elem;

int					ls_start(char *path, t_elem *all);

int					ls_storage(t_elem *all);
int					ls_print(t_elem *all);

int					ls_exit(int rtr);

#endif
