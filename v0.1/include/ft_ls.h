
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/02 16:14:13 by kboddez          ###   ########.fr       */
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
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

/*
**	MACROS TYPE
*/
# define bug(x) ft_strendl(x)
# define t_pwd struct passwd
# define t_group struct group
# define t_dirent struct dirent
# define t_stat struct stat

/*
**	MACROS OPTIONS
*/
# define OP_l (ops[0] == 1)
# define OP_R (ops[1] == 1)
# define OP_a (ops[2] == 1)
# define OP_r (ops[3] == 1)
# define OP_t (ops[4] == 1)


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
# define F_FILE all->f_file
# define PATH all->path
# define OLD_PATH all->old_path
# define IS_DIR all->is_dir
# define NEXT all->next
# define PREV all->prev
# define RECUR all->recur
# define ST_ATIME all->infos.st_atime
# define PERM all->perm
# define HARD_LINK all->hard_link
# define OWNER all->owner
# define GROUP all->group
# define SIZE all->size
# define TIME all->time

/*
**	MACROS FOR INFOS STORAGE (=struct 'stc')
*/
# define I stc->i
# define J stc->j
# define HOUR stc->hour
# define YEAR stc->year
# define MONTH_DAY stc->month_day
# define STC_TMP stc->tmp
# define STC_NOW stc->now

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
**	STRUCT FOR TIME STORAGE
*/
typedef struct  	s_tmp_time
{
	struct tm		*tmp;
	char			year[5];
	char			hour[9];
	char			month_day[10];
	int				i;
	int				j;
	time_t			now;
}					t_tmp_time;

/*
**	LINKED LIST FOR DIR/FILES
*/
typedef struct		s_elem
{
	char			*file_name;
	char			*path;
	char			*old_path;
	size_t			is_dir;
	char			perm[12];
	char			*hard_link;
	char			*owner;
	char			*group;
	char			*size;
	char			time[8];

	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*recur;
}					t_elem;

int					ls_start(int ops[5], char *path, t_elem *all);

int					ls_storage_dir(t_elem *all);
int					ls_storage_file(t_elem *all);
int					ls_print(int ops[5], t_elem *all);

int					ls_exit(int rtr);

/*
**	SORT FUNCTIONS
*/
void				ls_sort(int ops[5], t_elem *all);
void				ls_link_swap(t_elem *prev, t_elem *link_2, t_elem *link_1,\
								 t_elem *all);
//void				ls_reverse_sort(t_elem **all);

/*
**	FUNCTIONS TO ASSEMBLE INFOS
*/
void				ls_infos(t_store *store, t_stat *infos, t_elem *all);
void				ls_permission(t_stat infos, t_elem *all);
void				ls_owner(t_stat *infos, t_elem *all);
void				ls_group(t_stat *infos, t_elem *all);
void				ls_time(t_stat *infos, t_elem *all);

#endif
