/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:52:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/10 13:59:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*array;
	unsigned char	temp;
	size_t			i;

	i = 0;
	temp = c;
	array = b;
	while (i < len)
	{
		*(array + i) = temp;
		i++;
	}
	return (b);
}
