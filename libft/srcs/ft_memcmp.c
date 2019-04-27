/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:12:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/10 14:07:50 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	i = 0;
	while (str1[i] == str2[i] && i + 1 < n)
		i++;
	return (str1[i] - str2[i]);
}
