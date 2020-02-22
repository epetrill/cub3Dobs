/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:04:40 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:04:42 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*c_dst;
	unsigned char		*c_src;
	const unsigned char	c_c = c;

	c_src = (unsigned char *)src;
	c_dst = dst;
	while (n && *c_src != c_c)
	{
		*c_dst++ = *c_src++;
		n--;
	}
	if (n == 0)
		return (0);
	*c_dst++ = c_c;
	return (c_dst);
}
