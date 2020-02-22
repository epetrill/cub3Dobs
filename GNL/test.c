/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:12:05 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 00:40:17 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*res;
	int		fd;
	int		ret;

	ret = 1;
	fd = open("texte.txt", O_RDONLY);
	while (get_next_line(fd, &res))
	{
		printf("%s\n", res);
		free(res);
	}
	free(res);
	close(fd);
}
