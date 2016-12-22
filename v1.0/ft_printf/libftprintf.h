/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:32:15 by kboddez           #+#    #+#             */
/*   Updated: 2016/12/07 14:54:10 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <wchar.h>
# define PA mem->pa
# define STR mem->str
# define OUT mem->out
# define D mem->d
# define U mem->u
# define C mem->c
# define CHECK mem->check
# define SIGN mem->sign
# define NB_SIGN mem->nb_sign
# define SIGN_CHECK mem->sign_check
# define NB_READ mem->nb_read
# define NB_PREC mem->nb_prec
# define PREC_CHECK mem->prec_check
# define WOUT mem->wout
# define FLAG_TYPE mem->flag_type
# define MNB mem->memnb_sign
# define PRINT ft_print(type, mem);

typedef struct			s_mem
{
	va_list				pa;
	char				*str;
	long long			d;
	uintmax_t			u;
	int					check;
	int					flag_type;
	int					nb_prec;
	int					prec_check;
	wchar_t				c;
	char				*out;
	wchar_t				*wout;
	unsigned int		nb_read;
	char				sign;
	int					nb_sign;
	int					memnb_sign;
	int					sign_check;
}						t_mem;

typedef struct			s_bin
{
	unsigned char		bin0;
	unsigned char		bin1;
	unsigned char		bin2;
	unsigned char		bin3;
	unsigned int		mask0;
	unsigned int		mask1;
	unsigned int		mask2;

}						t_bin;

typedef struct			s_itoa
{
	int	i;
	int	neg;
	int	cpt;
}						t_itoa;

int						ft_printf(char *str, ...);
void					ft_int(char type, t_mem *mem);
void					ft_string(char type, t_mem *mem);
void					ft_char(char type, t_mem *mem);
void					ft_ptr(t_mem *mem);
int						ft_options_sign_i(char type, t_mem *mem);
void					ft_options_sign_iii(t_mem *mem);
char					*ft_unput(uintmax_t u);
char					*ft_itoa_maj(uintmax_t n, int base, int maj);
void					ft_format_i(char type, t_mem *mem);
void					ft_format_ii(char type, t_mem *mem);
void					ft_format_iii(char type, t_mem *mem);
void					ft_format_iv(char type, t_mem *mem);
void					ft_format_v(char type, t_mem *mem);
void					ft_option(char type, t_mem *mem);
int						ft_length(char type, t_mem *mem, int mod);
void					ft_print(char type, t_mem *mem);
int						ft_putstr_cpt(char type, t_mem *mem);
void					ft_error(int code);
int						ft_check(t_mem *mem);
void					ft_putwchar(wchar_t sign, t_mem *mem);
void					ft_putwstr(t_mem *mem);
int						ft_wlen(wchar_t w);
void					ft_precision(char type, t_mem *mem);
int						ft_test(char c);

char					*printf_itoa(long long int n);
char					*ft_itoa_base(int d, int base);
int						printf_nbr_length(int d, t_mem *mem);
void					ft_putchar(char c);
void					ft_putstr(char *str);
char					*ft_strnew(size_t size);
int						ft_isascii(int c);
void					*ft_memalloc(size_t size);
void					ft_bzero(void *s, size_t n);
void					ft_putnbr(int n);
void					ft_nbrendl(int n);
size_t					ft_strlen(const char *c);
int						printf_isdigit(int c);

#endif
