/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:59:11 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:01:07 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_aff_c(va_list vl, t_info list, int choice)
{
	if (list.width < 0)
	{
		list.width = -list.width;
		list.minus == 0 ? list.minus = 1 : 0;
	}
	if (list.minus == -1 && list.width > 0)
		while (list.width-- > 1)
		{
			if (list.zero == 1 && list.minus == -1)
				list.count = ft_putcount(list, '0', 1);
			else
				list.count = ft_putcount(list, ' ', 1);
		}
	list.count = choice == 0 ? ft_putcount(list, va_arg(vl, int), 1)
		: ft_putcount(list, '%', 1);
	if (list.minus == 1 && list.width > 0)
		while (list.width-- > 1)
		{
			if (list.zero == 1 && list.minus == -1)
				list.count = ft_putcount(list, '0', 1);
			else
				list.count = ft_putcount(list, ' ', 1);
		}
	return (list.count);
}

int		ft_aff_p(va_list vl, t_info list)
{
	unsigned long	a;
	unsigned long	tmp;
	int				len;

	len = 3;
	a = (unsigned long)va_arg(vl, void *);
	tmp = a;
	while (tmp /= 16)
		len++;
	if (list.precision != -1 && list.width > 2 && a == 0)
		list.width++;
	if (len < list.width && list.minus == -1)
		list.count = ft_putcount(list, ' ', list.width - len);
	ft_putcount(list, '0', 1);
	ft_putcount(list, 'x', 1);
	if (!(list.precision == 0 && a == 0))
	{
		ft_putnbr_16(a, 0);
		list.count += len;
	}
	else
		list.count += 2;
	if (len < list.width && list.minus == 1)
		list.count = ft_putcount(list, ' ', list.width - len);
	return (list.count);
}

int		ft_aff_s(va_list vl, t_info list)
{
	int		width;
	char	*tmp;
	int		len;

	tmp = ft_strdup(va_arg(vl, char *));
	tmp == NULL ? tmp = ft_strdup("(null)") : 0;
	len = ft_strlen(tmp);
	if (list.precision > -1)
		list.precision < len ? tmp[list.precision] = '\0' : 0;
	len = ft_strlen(tmp);
	width = list.width > list.precision ? list.width - len
		: 0;
	if (len <= list.width)
		width = list.width - len;
	if (list.minus == -1 && width > 0 && list.width > 0)
		while (width-- > 0)
			list.count = ft_ifaffs(list);
	ft_putstr_fd(tmp, 1);
	list.count = list.count + len;
	if (list.minus == 1 && width > 0 && list.width > 0)
		while (width-- > 0)
			list.count = ft_ifaffs(list);
	free(tmp);
	return (list.count);
}

int		ft_aff_di(va_list vl, t_info list, int choice)
{
	long int	a;
	int			len;
	const int	chg = list.precision == -1 ? 0 : 1;
	int			neg;

	if (choice == 0)
		a = va_arg(vl, int);
	if (choice == 1)
		a = va_arg(vl, unsigned);
	neg = a < 0 ? 1 : 0;
	if (a == 0 && list.precision == 0)
		return (list.count = ft_putcount(list, ' ', list.width));
	len = ft_count(a, 10);
	a < 0 ? list.precision++ : 0;
	list.precision < len ? list.precision = 0 : 0;
	list.precision >= len ? list.precision -= len : 0;
	list.width = list.width - len - list.precision;
	if (a < 0 && ((list.precision > 0 && list.width <= 0) || (list.zero == 1
		&& (list.precision > list.width || chg == 0))))
	{
		ft_putcount(list, '-', 1);
		a *= -1;
	}
	list.count = ft_affdi2(list, a, chg, neg) + len;
	return (list.count);
}

int		ft_aff_x(va_list vl, t_info list, int choice)
{
	unsigned int	a;
	int				len;
	const int		chg = list.precision == -1 ? 0 : 1;

	a = va_arg(vl, int);
	if (a == 0 && list.precision == 0)
		return (list.count = ft_putcount(list, ' ', list.width));
	len = ft_count(a, 16);
	list.precision < len ? list.precision = 0 : 0;
	list.precision >= len ? list.precision -= len : 0;
	list.width = list.width - len - list.precision;
	if (((list.zero == -1 || ((a == UINT_MAX || a == 0) && chg)) ||
			(chg && list.width > 0)) && list.width > 0 && list.minus == -1)
		list.count = ft_putcount(list, ' ', list.width);
	else if (list.zero == 1 && list.width > 0 && list.minus == -1)
		list.count = ft_putcount(list, '0', list.width);
	if (list.precision > 0)
		list.count = ft_putcount(list, '0', list.precision);
	ft_putnbr_16(a, choice);
	list.count += len;
	if (list.zero == -1 && list.width > 0 && list.minus == 1)
		list.count = ft_putcount(list, ' ', list.width);
	else if (list.zero == 1 && list.width > 0 && list.minus == 1)
		list.count = ft_putcount(list, '0', list.width);
	return (list.count);
}
