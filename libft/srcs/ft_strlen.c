/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 07:13:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/12 15:00:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str != (char*)0 && str[i])
		i++;
	return (i);
}
