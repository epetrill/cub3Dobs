/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:23:11 by epetrill          #+#    #+#             */
/*   Updated: 2020/03/01 06:50:14 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		free_tab(char **map,int choice)
{
	int i ;

	i = 0;
	printf("1.choice ==%d\n", choice);
	while (map[i])
	{
		printf("|%s|\n", map[i]);
		free(map[i]);
		i++;
	}
	printf("2.choice ==%d\n", choice);
	if (choice == 1)
		free(map);
}

char	*ft_strdup_mod(const char *s1)
{
	char	*c_s1;
	char	*start;

	if (!s1)
		return (NULL);
	c_s1 = malloc(ft_strlen(s1) + 1);
	if (!(start = c_s1))
		return (NULL);
	while (*s1)
	{
		if (*s1 != ' ')
			*c_s1++ = *s1++;
		else 
			s1++;
	}
	*c_s1 = 0;
	return (start);
}

int	main(int ac, char **av)
{
//	t_mapinfo *info_map;
	char **map;
	int i;

	i = 0;
	map = NULL;
	if (ac != 2)
		return (ft_error("Wrong arg nbrs for ./cub\n", NULL));
	if ((map = cpy_map(av[1],  map)) == NULL)
		return (0);
	aff_tab(map);
	free_tab(map, 0);
	return (0);
}

char **cpy_map(char *fichier, char **map)
{
	int gnl_ret;
	int fd;
	int len;

	len = ft_strlen(fichier);
	gnl_ret = 1;
	fd = 0;
	if (!(map = malloc(2 * (sizeof(*map)))))
		return (ft_perror("Issue during malloc map lines", NULL));
	map[0] = NULL;
	map[1] = NULL;
	if (len < 5 || ft_strncmp(".cub", &fichier[len - 4], 4) != 0)
		return (ft_perror("Issue with the map name\n", map));
	len = 0;
	if (!(fd = open(fichier, O_RDONLY)))
		return (ft_perror("Issue during file opening\n", map));
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &map[len]);
		len++;
		if ((map = realloc_map(map, len + 1)) == NULL)
			return (NULL);
	}
	return (map);
}


void aff_tab(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**realloc_map(char **map, int size)
{
	char **tmp;
	int i;

	i = 0;
	printf("A\n");
	if (!(tmp = malloc((size + 1) * sizeof(*tmp))))
		return (ft_perror("Issue during realloc map\n", map));
	while (map[i])
	{
		tmp[i] = ft_strdup_mod(map[i]);
		i++;
	}
	tmp[size] = NULL;;
	free_tab(map, 1);
	printf("B\n");
	return (tmp);
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
		free_tab(map, 1);
	printf("Error\n");
	printf("%s", str);
	return (-1);
}

char	**ft_perror(char *str, char **map)
{
	if (map)
		free_tab(map, 1);
	printf("Error\n");
	printf("%s", str);
	return (NULL);
}
