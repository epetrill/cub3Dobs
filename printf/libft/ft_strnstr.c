/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:06:54 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:06:57 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	len_needle = ft_strlen(needle);
	char			*index;

	if (!len_needle)
		return ((char*)haystack);
	if (!len)
		return (0);
	index = ft_strchr(haystack, *needle);
	while (index && len - (index - haystack) >= len_needle)
	{
		if (!ft_memcmp(index, needle, len_needle))
			return (index);
		index = ft_strchr(index + 1, *needle);
	}
	return (0);
}
