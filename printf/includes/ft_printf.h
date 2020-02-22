/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:01:37 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:02:16 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_info
{
	int			width;
	int			precision;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			hash;
	int			count;
	char		*help;
}				t_info;

void			ft_putnbr_16(unsigned long nbr, int choice);
int				ft_putcount(t_info list, char c, int nb);
int				ft_skip(char *str);
int				ft_increment(char *str);
t_info			ft_parsing(char *str, va_list vl, t_info list);
t_info			ft_parsing2(va_list vl, t_info list);
t_info			ft_parsing3(va_list vl, t_info list);
t_info			ft_createstruct(t_info list);
int				ft_printf(const char *str, ...)
 __attribute__((format(printf,1,2)));
int				ft_distrib(char *str, va_list vl, t_info list);
int				ft_count(long long n, int base);
int				ft_isflag(char c);
int				ft_aff_c(va_list vl, t_info list, int choice);
int				ft_aff_p(va_list vl, t_info list);
int				ft_aff_s(va_list vl, t_info list);
int				ft_aff_di(va_list vl, t_info list, int choice);
int				ft_aff_x(va_list vl, t_info list, int choice);
int				ft_aff_u(va_list vl, t_info list);
int				*ft_convhex(int nb, int choice);
int				ft_ifaffs(t_info list);
int				ft_affdi2(t_info list, long int a, const int chg, int neg);

#endif
