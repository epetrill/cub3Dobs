/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:02:47 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:02:48 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	const size_t	res = count * size;

	if (!(ptr = malloc(res)))
		return (NULL);
	ft_bzero(ptr, res);
	return (ptr);
}
