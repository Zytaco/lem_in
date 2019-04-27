/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:42:55 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/12 15:06:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2
# include <string.h>

int					get_next_line(const int fd, char **line);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
int					ft_strnchr(const char *s, int c);
char				*ft_strnew(size_t size);

#endif
