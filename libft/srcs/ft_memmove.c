/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:03:01 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 16:26:58 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tempdst;
	char const	*tempsrc;

	tempdst = dst;
	tempsrc = src;
	if (dst >= src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			tempdst[i] = tempsrc[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	return (dst);
}
