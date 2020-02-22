/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:06:17 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:06:19 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	len_dst = ft_strlen(dst);
	const size_t	len_src = ft_strlen(src);
	size_t			i;

	i = 0;
	if (!size)
		return (len_src);
	if (size == len_dst)
		return (len_src + len_dst);
	if (size < len_dst)
		return (len_src + size);
	while (src[i] && i < size - len_dst - 1)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = 0;
	return (len_dst + len_src);
}
