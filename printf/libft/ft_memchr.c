/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:04:45 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:04:47 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*c_s;
	const unsigned char	c_c = c;

	c_s = (unsigned char*)s;
	i = 0;
	while ((i < n) && c_s[i] != c_c)
		i++;
	if (i == n)
		return (0);
	else
		return (c_s + i);
}
