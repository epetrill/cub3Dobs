/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:06:23 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:06:25 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (!(src && dst))
		return (0);
	src_len = ft_strlen(src);
	if (size)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (src_len);
}
