/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:08:17 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 13:10:29 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (i + j < size && src[j] != 0)
	{
		if (i + j + 1 < size)
			dst[i + j] = src[j];
		else
			dst[i + j] = 0;
		j++;
	}
	if (src[j] == 0)
		dst[i + j] = 0;
	while (src[j] != 0)
		j++;
	return (i + j);
}
