/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:07:10 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:07:12 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	k = 0;
	while (ft_find((char)s1[i], (char *)set) && s1[i])
		i++;
	if (s1[i] == '\0')
		return (ft_calloc(1, 1));
	while (ft_find((char)s1[j], (char *)set) && j >= i)
		j--;
	if (!(res = malloc(j - i + 1 + 1)))
		return (0);
	while (i <= j)
		res[k++] = s1[i++];
	res[k] = '\0';
	return (res);
}
