/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:05:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:05:52 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_splitclean(int max, char **res)
{
	while (max >= 0)
	{
		free(res[max]);
		max--;
	}
	free(res);
	return (NULL);
}

static int		nb_words(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 1;
	if (s[i] == c)
		count--;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char		*ft_cplit(char *str, char c, int start)
{
	int		tmp;
	int		i;
	char	*cpy;

	i = 0;
	tmp = start;
	while (str[tmp] && str[tmp] != c)
		tmp++;
	if (!(cpy = ft_calloc((tmp - start + 1), sizeof(cpy))))
		return (0);
	while (str[start] && str[start] != c)
	{
		cpy[i] = str[start];
		start++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	int		nb_ligne;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	nb_ligne = nb_words((char *)s, c);
	if (!(res = ft_calloc((nb_ligne + 1), sizeof(res))))
		return (0);
	while (s[i] && j < nb_ligne)
	{
		while (s[i] && s[i] == c)
			i++;
		if ((res[j] = ft_cplit((char *)s, c, i)) == 0)
			return (ft_splitclean(j - 1, res));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	res[nb_ligne] = 0;
	return (res);
}
