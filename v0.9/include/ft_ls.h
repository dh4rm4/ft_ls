/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/20 14:32:42 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**	 ############################################################
**	##															##
**	##					OPTIONS AVALAIBLES						##
**	##	BASICS ;												##
**	##	-l : list infos about file / directory					##
**	##	-R : recusively print argument(s)						##
**	##	-a : print also hidden file(s)							##
**	##	-r : reverse output										##
**	##	-t : sort output by time								##
**	##															##
**	##	------------------------------------------------------	##
**	##															##
**	##	BONUS ;													##
**	##	-A : like -a but without print "." & ".."				##
**	##	-d : list directory as plain file						##
**	##	-F : add char at the end of "FILE_NAME"					##
**	##		/ -> directory										##
**	##		@ -> symbolic link									##
**	##		* -> executable										##
**	##	   \0 -> regular file									##
**	##		= -> socket											##
**	##		% -> witheout										##
**	##		| -> fifo											##
**	##	-i : print inode number of file							##
**	##	-o : delete the group name of option -l output			##
**	##	-u : sort with time of last access instead last modif	##
**	##															##
**	 ############################################################
*/

/*
**	INCLUDES
*/
# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"
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
# define T_PWD struct passwd
# define T_GROUP struct group
# define T_STAT struct stat

/*
**	MACROS COLOR
*/
# define RED "\033[33;31m"
# define GREEN "\033[33;32m"
# define YELLOW "\033[33;33m"
# define BLUE "\033[33;34m"
# define PINK "\033[33;35m"
# define WHITE "\033[33;37m"

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
# define OP_F (ops[7] == 1)
# define OP_I (ops[8] == 1)
# define OP_O (ops[9] == 1)
# define OP_U (ops[10] == 1)

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
# define H_Y all->hour_year
# define TIME_MEM all->time_mem
# define MAJOR all->major
# define MINOR all->minor
# define RDEV all->rdev
# define BLOCKS all->blocks
# define INODE all->inode
# define DLINK all->dlink

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
	char			hour_year[5];
	char			*major;
	char			*minor;
	time_t			time_mem;
	dev_t			rdev;
	int				blocks;
	ino_t			inode;
	char			dlink[256];

	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*recur;
}					t_elem;

/*
**	PART OF ARGS FUNCITONS && BEGIN FT_LS
*/
void				ls_arg(int ops[11], int ac, char *av[], t_elem *all);
int					ls_nb_options(int ops[11]);
int					ls_start(int ops[11], char *path, t_elem *all);

/*
**	OUTPUT FUNCITONS
*/
int					ls_print(int check, int ops[11], t_elem *all);
void				ls_color(T_STAT stat);
int					ls_blocks(int ops[11], t_elem *all);

/*
**	SORT FUNCTIONS
*/
void				ls_sort(int ops[11], t_elem *all);
int					ls_lst_length(t_elem *all);
void				ls_link_swap(t_elem *prev, t_elem *link_2, t_elem *link_1, \
								t_elem *all);
void				ls_time_sort(int ops[11], t_elem *all);

/*
**	FUNCTIONS TO ASSEMBLE INFOS
*/
int					ls_storage_dir(int ops[11], t_elem *all);
int					ls_storage_file(int ops[11], t_elem *all);
void				ls_infos(int ops[11], t_store *store, T_STAT *infos, \
							t_elem *all);
void				ls_permission(T_STAT infos, t_elem *all);
void				ls_owner(T_STAT *infos, t_elem *all);
void				ls_group(T_STAT *infos, t_elem *all);

int					ls_exit(int rtr, char *path);
void				ls_free(t_elem *all);

#endif
