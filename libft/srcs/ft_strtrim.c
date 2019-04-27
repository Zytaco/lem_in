/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:13:33 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/10 14:02:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != 0 && (s[i] == ' ' || (9 <= s[i] && s[i] <= 13)))
		i++;
	while (s[i + j] != 0 && s[i + j + 1] != 0)
		j++;
	while (s[i + j] == ' ' || (9 <= s[i + j] && s[i + j] <= 13))
		j--;
	str = (char *)malloc(sizeof(char) * (j + 2));
	if (str == NULL)
		return (NULL);
	str[j + 1] = 0;
	while (j + 1 > 0)
	{
		str[j] = s[i + j];
		j--;
	}
	return (str);
}
