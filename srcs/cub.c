/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:23:11 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/25 00:19:06 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tab(char **map)
{
	int i ;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

int	main(int ac, char **av)
{
//	t_mapinfo *info_map;
	char **map;

	map = NULL;
	if (ac != 2)
		return (ft_error("Wrong arg nbrs for ./cub\n", map));
	if (cpy_map(av[1],  map) == -1)
		return (-1);
	/*if (cleanmap( map) == -1)
		return (-1);*/
	return (0);
}

int cpy_map(char *fichier, char **map)
{
	int gnl_ret;
	int fd;
	int len;

	len = ft_strlen(fichier);
	gnl_ret = 1;
	fd = 0;
	if (!(map = ft_calloc(1, (sizeof(map)))))
		return (ft_error("Issue during malloc map lines", map));
	if (len < 5 || ft_strncmp(".cub", &fichier[len - 4], 4) != 0)
		return (ft_error("Issue with the map name\n", map));
	len = 0;
	if(!(fd = open(fichier, O_RDONLY)))
		return (ft_error("Issue during file opening\n", map));
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &map[len]);
		len++;
		if (realloc_map(map, len) == -1)
			return (-1);
	}
	map[len] = NULL;
	return (0);
}

//int cleanmap(char **map, 

void aff_tab(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

int	realloc_map(char **map, int size)
{
	char **tmp;
	int i;

	i = 0;
	if(!(tmp = ft_calloc(size + 1, sizeof(tmp))))
		return (ft_error("Issue during realloc map\n", map));
	tmp = NULL;
	printf("1\n");
	while (map[i++])
		tmp[i] = ft_strdup(map[i]);
	printf("a\n");
	tmp[i] = NULL;
	free_tab(map);
	if(!(map = ft_calloc((size + 1), sizeof(map))))
		return(ft_error("Issue during realloc map\n", map));
	i = 0;
	while (tmp[i])
	{
		map[i] = tmp[i];
		i++;
	}
	map[i] = ft_strdup(NULL);
	free_tab(tmp);
	return (0);
}
int init_mapinfo(t_mapinfo *pinfo, char **map)
{
	t_mapinfo info;

	if (!(pinfo = malloc(sizeof(info))))
		return (ft_error("Issue during struc info malloc\n", map));
	pinfo = &info;
	info.res = NULL;
	info.north = NULL;
	info.south = NULL;
	info.east = NULL;
	info.west = NULL;
	info.sprite = NULL;
	info.floor = NULL;
	info.ceiling = NULL;
	return (0);
}

int ft_error(char *str, char **map)
{
	if (map)
		free_tab(map);
	printf("Error\n");
	printf("%s", str);
	return (-1);
}

/*int init_error(t_error *plist)
{
	t_error list;

	if (!(plist = malloc(sizeof(s_error))))
		return (ft_error("Issue during malloc 1\n"));
	plist = &list;
	list.arg = 0;
	list.cl_map = 0;
	list.check_sprite = 0;
	list.check_NO = 0;
	list.check_SO = 0;
	list.check_WE = 0;
	list.check_EA = 0;
	list.check_res = 0;
	list.check_floor = 0;
	list.check_ceiling = 0;
	list.check_all = 0;
}

int	check_error(t_error *list)
{
	if (*list.cl_map)
		return (ft_error("Map isn't valid !\n"));
	if (*list.check_sprite)
		return (ft_error("Sprite texture undefined !\n"));
	if (*list.check_NO)
		return (ft_error("North texture undefined !\n"));
	if (*list.check_SO)
		return (ft_error("South texture undefined !\n"));
	if (*list.check_WE)
		return (ft_error("West texture undefined !\n"));
	if (*list.check_EA)
		return (ft_error("East texture undefined !\n"));
	if (*list.check_res)
		return (ft_error("Resolution undefined !\n"));
	if (*list.check_floor)
		return (ft_error("Floor texture undefined !\n"));
	if (*list.check_ceiling)
		return (ft_error("Ceiling texture undefined !\n"));
	return (0);
}
*/
