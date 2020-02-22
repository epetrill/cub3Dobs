/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:07:18 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:07:19 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	unsigned int	dsize;

	dsize = 0;
	i = 0;
	if (s == 0)
		return (NULL);
	while (s[dsize])
		dsize++;
	if (start > dsize)
		return (ft_calloc(1, 1));
	if (!(res = malloc(len + 1)))
		return (0);
	dsize = start;
	while (s[dsize] && i < len)
		res[i++] = s[dsize++];
	res[i] = '\0';
	return (res);
}
