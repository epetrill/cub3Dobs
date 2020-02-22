/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:23:11 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/22 22:50:34 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_error error_list;

	init_error (error_list);
	if (ac != 2)
		error_list.arg = 1;
	else
	{
		cpy_map(av[1], error_list);
	}
	return (0);
}

void	check_error(s_error list)
{
	if (list.arg)
		printf("ERREUR 1 : Mauvais nombre d'arguments pour ./cub !");

}

void	init_error(s_error list)
{
	list.arg = 0;
	list.
}

int	ft_error(
