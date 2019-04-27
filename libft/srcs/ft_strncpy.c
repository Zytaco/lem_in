/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:44:12 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/07 14:13:35 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (src[i + j] != 0)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			j--;
		}
		i++;
	}
	return (dst);
}
