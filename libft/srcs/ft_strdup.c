/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:13:43 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/25 16:36:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		length;
	int		i;

	length = 0;
	while (src[length])
		length++;
	cpy = (char*)malloc(sizeof(char) * (length + 1));
	if (cpy == (char*)0)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = src[i];
	return (cpy);
}
