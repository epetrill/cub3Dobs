/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:42:04 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 13:55:22 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info	ft_parsing(char *str, va_list vl, t_info list)
{
	str++;
	list = ft_createstruct(list);
	while (*str == '-' || *str == '0' || *str == '+' || *str == ' '
			|| *str == '#')
	{
		*str == '-' ? list.minus = 1 : 0;
		*str == '0' ? list.zero = 1 : 0;
		*str == '+' ? list.plus = 1 : 0;
		*str == ' ' ? list.space = 1 : 0;
		*str == '#' ? list.hash = 1 : 0;
		str++;
	}
	list.help = str;
	list = ft_parsing2(vl, list);
	list = ft_parsing3(vl, list);
	if (!ft_isflag(*(list.help)))
		return (list);
	else
		list.count = ft_distrib(list.help, vl, list);
	return (list);
}

t_info	ft_parsing2(va_list vl, t_info list)
{
	if (ft_isdigit(*(list.help)))
	{
		list.width = ft_atoi(list.help);
		if (list.width < 0)
		{
			list.minus = 1;
			list.width = -list.width;
		}
		list.help = list.help + ft_increment(list.help);
	}
	if (*(list.help) == '*')
	{
		list.width = va_arg(vl, int);
		if (list.width < 0)
		{
			list.minus = 1;
			list.zero = -1;
			list.width = -list.width;
		}
		list.help++;
	}
	return (list);
}

t_info	ft_parsing3(va_list vl, t_info list)
{
	if (*(list.help) == '.')
	{
		list.help++;
		if (ft_isdigit(*(list.help)))
		{
			list.precision = ft_atoi(list.help);
			list.help = list.help + ft_increment(list.help);
		}
		else if (*(list.help) == '*')
		{
			list.precision = va_arg(vl, int);
			list.help++;
		}
		else
			list.precision = 0;
	}
	return (list);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list	vl;
	t_info	list;

	list.count = 0;
	i = 0;
	va_start(vl, str);
	while (*str)
	{
		if (*str == '%')
		{
			list = ft_parsing((char *)str, vl, list);
			str = str + ft_skip((char *)str);
		}
		else
			list.count = ft_putcount(list, (char)*str, 1);
		str++;
	}
	va_end(vl);
	return (list.count);
}
