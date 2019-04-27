/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:38:00 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:25:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
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
}
