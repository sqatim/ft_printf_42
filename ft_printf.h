/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:32:45 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/31 18:58:40 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_list
{
	char				c;
	char				*str;
	char				cvrs;
	int					signe;
	int					j;
	int					i;
	unsigned int		u;
	unsigned int		x;
	unsigned long long	ptr;
	int					count;
	int					w;
	int					p;
	int					len;
	va_list				ap;
}				t_list;

int				ft_printf(const char *format, ...);
void			ft_rempl_ntr(t_list *data);
void			ft_psrmpl_nbr(int cmp, t_list *data);
void			ft_psrmpl_str(char *str, t_list *data);
void			ft_psrmpl_crt(char *str, t_list *data);
void			ft_psrmpl_ptr(t_list *data);
void			ft_ntrrmpl_num(int cmp, t_list *data);
void			ft_ntrrmpl_str(t_list *data);
void			ft_ntrrmpl_crt(t_list *data);
void			ft_ntrrmpl_ptr(t_list *data);
void			ft_width_al(char *str, int size, t_list *data);
void			ft_width_nbr(int size, char *str, t_list *data);
void			ft_width_ptr(char *str, t_list *data);
void			ft_print_width(int size, char *str, t_list *data);
void			ft_putstr(char *c, t_list *data);
void			ft_putnbr(int nbr, t_list *data);
void			ft_printadd(unsigned long long nbr, t_list *data);
void			ft_printhexa(unsigned int nbr, int k, t_list *data);
void			ft_print_cvr(t_list *data);
void			ft_putunsigned(unsigned int nbr, t_list *data);
void			ft_putchar(char c, t_list *data);
void			ft_space(int k, t_list *data);
void			ft_zero(int k, t_list *data);
void			ft_topos(t_list *data);
void			ft_ext_putstr(t_list *data);
int				count_int(int nb);
int				count_unsigned(unsigned int nb);
int				ft_count_alpha(t_list *data);
int				ft_count_add(unsigned long long nbr);
int				ft_count_hexa(unsigned int nbr);
int				ft_count_alnum(t_list *data);
int				ft_cvrs_count(t_list *data);
int				ft_count_digit(t_list *data);
int				cnt_to_cvr(char *str);
void			ft_check_print(int res, t_list *data);
void			ft_precision(int res, char *str, t_list *data);
void			ft_just_width(int res, char *str, t_list *data);
void			ft_just_cvrs(t_list *data);
void			ft_pos_alnum(char *str, int nbr, t_list *data);
void			ft_signe(int nb, char *str, t_list *data);
void			ft_isnega(t_list *data);
void			ft_ispost(char *str, int nbr, t_list *data);
int				ft_exp_precision(char *str, t_list *data);
int				ft_etoile(char *str, t_list *data);
int				comparaison(t_list *data);
int				ft_exp_width(char *str, t_list *data);
void			ft_flags(char *str, t_list *data);
void			ft_check(t_list *data);
int				ft_determination(char *str, t_list *data);
int				ft_deter_prc(int index, char *str, t_list *data);

#endif
