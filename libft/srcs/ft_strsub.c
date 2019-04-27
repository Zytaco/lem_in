/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:18:41 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:01:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (str);
	str[len] = '\0';
	i = (size_t)start;
	while (i - (size_t)start < len)
	{
		str[i - (size_t)start] = s[i];
		i++;
	}
	return (str);
}
