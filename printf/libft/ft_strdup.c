/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:06:05 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:06:07 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c_s1;
	char	*start;

	if (!s1)
		return (NULL);
	c_s1 = malloc(ft_strlen(s1) + 1);
	if (!(start = c_s1))
		return (NULL);
	while (*s1)
		*c_s1++ = *s1++;
	*c_s1 = 0;
	return (start);
}
