
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/05 18:46:31 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**	 ####################################################
**	##				MENU OPTIONS						##
**	##	BASICS ;										##
**	##	-l : list infos about file / directory			##
**	##	-R : recusively print argument(s)				##
**	##	-a : print also hidden file(s)					##
**	##	-r : reverse output								##
**	##	-t : sort output by time						##
**	##													##
**	##	----------------------------------------------	##
**	##													##
**	##	BONUS ;											##
**	##	-A : like -a but without print "." & ".."		##
**	##	-d : list directory as plain file				##
**	##													##
**	 ####################################################
*/
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
# define T_PWD struct passwd
# define T_GROUP struct group
# define T_STAT struct stat

/*
**	MACROS OPTIONS
*/
# define OP_L (ops[0] == 1)
# define OP_R (ops[1] == 1)
# define OP_A (ops[2] == 1)
# define OP_RR (ops[3] == 1)
# define OP_T (ops[4] == 1)
# define OP_AA (ops[5] == 1)
# define OP_D (ops[6] == 1)

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
# define TIME_MEM all->time_mem
# define MAJOR all->major
# define MINOR all->minor
# define RDEV all->rdev
# define BLOCKS all->blocks

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
typedef struct		s_tmp_time
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
	char			*major;
	char			*minor;
	time_t			time_mem;
	dev_t			rdev;
	int				blocks;

	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*recur;
}					t_elem;

void				ls_arg(int ops[11], int ac, char *av[], t_elem *all);
int					ls_start(int ops[11], char *path, t_elem *all);

int					ls_storage_dir(t_elem *all);
int					ls_storage_file(t_elem *all);
int					ls_print(int check, int ops[11], t_elem *all);

int					ls_exit(int rtr);

/*
**	SORT FUNCTIONS
*/
void				ls_sort(int ops[11], t_elem *all);
int					ls_lst_length(t_elem *all);
void				ls_link_swap(t_elem *prev, t_elem *link_2, t_elem *link_1, \
								t_elem *all);
void				ls_time_sort(t_elem *all);

/*
**	FUNCTIONS TO ASSEMBLE INFOS
*/
void				ls_infos(t_store *store, T_STAT *infos, t_elem *all);
void				ls_permission(T_STAT infos, t_elem *all);
void				ls_owner(T_STAT *infos, t_elem *all);
void				ls_group(T_STAT *infos, t_elem *all);

#endif
