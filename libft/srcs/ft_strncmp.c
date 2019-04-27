/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 07:28:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 11:42:55 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	temp1;
	unsigned char	temp2;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i + 1 < n)
		i++;
	temp1 = (unsigned char)s1[i];
	temp2 = (unsigned char)s2[i];
	return (temp1 - temp2);
}
