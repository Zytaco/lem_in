/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrcut.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:53:25 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 13:53:25 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*ft_strncpy(char *dst, const char *src, size_t len)
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

static int	get_i(char const *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char		*ft_strrcut(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = get_i(s1);
	len = i;
	while (i >= 0)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
			j++;
		if (s1[i + j] == s2[j] && s2[j + 1] == '\0')
		{
			newstr = ft_strnew(sizeof(char) * (len - (j + 1)));
			if (newstr == NULL)
				return (NULL);
			ft_strncpy(newstr, s1, (size_t)(i + 1));
			ft_strncpy(newstr, s1 + i + (j + 1), (size_t)(len - (i + j + 1)));
			return (newstr);
		}
		i--;
	}
	return (s1);
}
