/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:37:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:21:34 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*ptr2;
	size_t	i;

	ptr = (void *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	ptr2 = ptr;
	i = 0;
	while (i < size)
	{
		ptr2[i] = 0;
		i++;
	}
	return (ptr);
}
