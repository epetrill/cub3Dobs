/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:06:39 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:06:40 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	if (!(ptr = malloc(i + 1)))
		return (0);
	ptr[i] = 0;
	while (i--)
		ptr[i] = f(i, s[i]);
	return (ptr);
}
