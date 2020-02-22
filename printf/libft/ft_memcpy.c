/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:04:57 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:04:58 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *c_dst;

	if (!dst && !src)
		return (0);
	c_dst = dst;
	while (n--)
		*c_dst++ = *(char *)src++;
	return (dst);
}
