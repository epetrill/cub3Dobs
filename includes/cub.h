/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:23:30 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/25 23:27:30 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../printf/includes/ft_printf.h"
# include "get_next_line.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"

/*typedef struct	s_error
{
	int cl_map;
	int check_sprite;
	int check_NO;
	int check_SO;
	int check_WE;
	int check_EA;
	int check_res;
	int check_floor;
	int check_ceiling;
	int check_all;

}				t_error;
*/
typedef struct	s_mapinfo
{
	int *res;
	char *north;
	char *south;
	char *east;
	char *west;
	char *sprite;
	int *floor;
	int *ceiling;
}				t_mapinfo;

char	**cpy_map(char *fichier, char **map);
char	**realloc_map(char **map, int size);
/*int		check_error(t_error *list);
int		init_error(t_error *plist);*/
int		ft_error(char *str, char **map);
char	**ft_perror(char *str, char **map);
void	aff_tab(char **map);
#endif
