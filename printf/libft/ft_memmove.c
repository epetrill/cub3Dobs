/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:05:03 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:05:04 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else if (dst != src)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}
