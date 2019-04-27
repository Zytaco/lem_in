/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:58:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:24:12 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	int i;

	if (s == (char*)0)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	write(1, "\n", 1);
}
