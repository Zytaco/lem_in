/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:03:00 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/05 13:05:20 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_assign_string(char *str, char const *s1, char const *s2)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
		i++;
	j = 0;
	while (s2 != NULL && s2[j])
		j++;
	str = (char *)malloc(sizeof(str) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	ft_assign_string(str, s1, s2);
	return (str);
}
