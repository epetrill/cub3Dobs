/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:07:03 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:07:04 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char*)s + ft_strlen(s);
	while (*s++ && *ptr != c)
		ptr--;
	if (*ptr == c)
		return (ptr);
	else
		return (0);
}
