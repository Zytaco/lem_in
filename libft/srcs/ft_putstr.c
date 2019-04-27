/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:56:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:25:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;

	if (s == (char*)0)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
}
