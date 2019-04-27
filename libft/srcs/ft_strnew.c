/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:37:13 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 18:09:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc(size + 1);
	i = 0;
	while (str == NULL && i < 100)
	{
		str = (char*)malloc(size + 1);
		i++;
	}
	if (str == NULL)
		return (NULL);
	str[size] = 0;
	while (size > 0)
	{
		str[size - 1] = 0;
		size--;
	}
	return (str);
}
