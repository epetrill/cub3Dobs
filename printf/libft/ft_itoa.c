/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:03:30 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:03:32 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char *str, unsigned int stock, int i, int n)
{
	if (n >= 0)
	{
		while (i >= 0)
		{
			str[i] = stock % 10 + 48;
			stock = stock / 10;
			i--;
		}
	}
	else
		while (i > 0)
		{
			str[i] = stock % 10 + 48;
			stock = stock / 10;
			i--;
		}
}

static int	ft_count(unsigned int stock, int n)
{
	int count;

	count = 0;
	if (stock == 0)
		count++;
	if (n < 0)
	{
		count++;
		stock = stock * -1;
	}
	while (stock != 0)
	{
		stock = stock / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*ret;
	unsigned int	stock;
	int				i;
	int				count;

	stock = n;
	count = ft_count(stock, n);
	if (!(ret = malloc(count + 1)))
		return (0);
	i = count - 1;
	if (n < 0)
	{
		stock = -stock;
		ret[0] = '-';
		ft_fill(ret, stock, i, n);
	}
	else
		ft_fill(ret, stock, i, n);
	ret[count] = '\0';
	return (ret);
}
