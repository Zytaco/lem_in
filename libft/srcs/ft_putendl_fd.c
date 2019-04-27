/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putend_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:40:14 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:24:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int i;

	if (s == (char*)0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}
