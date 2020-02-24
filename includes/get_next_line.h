/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:10:27 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 00:56:37 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

int		ft_read(int fd, char **res, char *buffer);
int		ft_rest(char *res, char *buffer);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_mod(char *s1, const char *s2);
int		ft_strchr_mod(const char *s);

#endif
