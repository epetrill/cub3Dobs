/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:04:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:04:52 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1 = s1;
	const unsigned char	*c_s2 = s2;
	size_t				i;

	i = 0;
	while (i < n && c_s1[i] == c_s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (c_s1[i] - c_s2[i]);
}
