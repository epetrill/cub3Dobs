/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:01:25 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:01:28 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_16(unsigned long nbr, int choice)
{
	char	*base;

	if (choice == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putnbr_16(nbr / 16, choice);
		ft_putnbr_16(nbr % 16, choice);
	}
	else if (nbr < 16)
		write(1, &base[nbr], 1);
}

int		ft_count(long long n, int base)
{
	int				count;

	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n /= base)
		count++;
	return (count);
}

int		ft_putcount(t_info list, char c, int nb)
{
	int count;

	count = nb;
	while (nb > 0)
	{
		ft_putchar_fd(c, 1);
		nb--;
	}
	return (list.count + count);
}

int		ft_skip(char *str)
{
	int a;

	a = 1;
	while (!ft_isflag(str[a]))
		a++;
	return (a);
}

int		ft_increment(char *str)
{
	int a;

	a = 0;
	while (ft_isdigit(str[a]))
		a++;
	return (a);
}
