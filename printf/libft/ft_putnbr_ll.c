/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:05:37 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:05:39 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll(long long int n, int fd)
{
	char b;

	if (n == LONG_MIN)
	{
		write(fd, "-9223372036854775808", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n < 10)
	{
		b = n + 48;
		write(fd, &b, 1);
	}
	if (n >= 10)
	{
		b = n % 10 + 48;
		ft_putnbr_ll(n / 10, fd);
		write(fd, &b, 1);
	}
}
