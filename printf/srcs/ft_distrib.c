/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:01:15 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:01:17 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isflag(char c)
{
	if (c == 'c')
		return (1);
	if (c == '%')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	return (0);
}

t_info	ft_createstruct(t_info list)
{
	list.width = 0;
	list.precision = -1;
	list.plus = -1;
	list.minus = -1;
	list.zero = -1;
	list.space = -1;
	list.hash = -1;
	return (list);
}

int		ft_distrib(char *str, va_list vl, t_info list)
{
	if (*str == 'c')
		list.count = ft_aff_c(vl, list, 0);
	else if (*str == '%')
		list.count = ft_aff_c(vl, list, 1);
	else if (*str == 'p')
		list.count = ft_aff_p(vl, list);
	else if (*str == 's')
		list.count = ft_aff_s(vl, list);
	else if (*str == 'd' || *str == 'i')
		list.count = ft_aff_di(vl, list, 0);
	else if (*str == 'x')
		list.count = ft_aff_x(vl, list, 0);
	else if (*str == 'X')
		list.count = ft_aff_x(vl, list, 1);
	else if (*str == 'u')
		list.count = ft_aff_di(vl, list, 1);
	else
		write(1, "ERROR", 5);
	return (list.count);
}

int		ft_ifaffs(t_info list)
{
	if (list.zero == 1 && list.minus == -1)
		list.count = ft_putcount(list, '0', 1);
	else
		list.count = ft_putcount(list, ' ', 1);
	return (list.count);
}

int		ft_affdi2(t_info list, long int a, const int chg, int neg)
{
	if ((list.zero == -1 || ((a == INT_MAX || a == 0 || a == UINT_MAX || neg)
			&& chg) || (chg && list.width > 0))
			&& list.width > 0 && list.minus == -1)
		list.count = ft_putcount(list, ' ', list.width);
	else if (list.zero == 1 && list.width > 0 && list.minus == -1)
		list.count = ft_putcount(list, '0', list.width);
	if (a < 0 && list.precision > 0 && list.width > 0)
	{
		ft_putcount(list, '-', 1);
		a *= -1;
	}
	if (list.precision > 0)
		list.count = ft_putcount(list, '0', list.precision);
	ft_putnbr_ll(a, 1);
	if (list.width > 0 && list.minus == 1)
		list.count = ft_putcount(list, ' ', list.width);
	return (list.count);
}
