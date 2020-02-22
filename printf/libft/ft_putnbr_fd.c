/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:05:30 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:05:31 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nombre;

	nombre = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nombre = nombre * (-1);
	}
	if (nombre > 9)
	{
		ft_putnbr_fd(nombre / 10, fd);
		ft_putnbr_fd(nombre % 10, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(nombre + 48, fd);
	}
}
