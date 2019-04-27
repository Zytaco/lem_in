/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:33:30 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/10 13:52:23 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		count_splits(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 0 && s[i] != c)
		{
			count++;
			while (s[i] != 0 && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static char			*assign_split(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = 0;
	while (i > 0)
	{
		i--;
		str[i] = s[i];
	}
	return (str);
}

static char const	*ft_skip_c_or_notc(char const *s, char c, int yesno)
{
	if (yesno == 1)
	{
		while (*s != 0 && *s == c)
			s++;
		return (s);
	}
	else if (yesno == 0)
	{
		while (*s != 0 && *s != c)
			s++;
		return (s);
	}
	else
		return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	split_count;
	char	**array;
	size_t	i;

	if (s == NULL)
		return (NULL);
	split_count = count_splits(s, c);
	array = (char**)malloc(sizeof(*array) * (split_count + 1));
	if (array == NULL)
		return (NULL);
	array[split_count] = 0;
	i = 0;
	while (*s && i < split_count)
	{
		s = ft_skip_c_or_notc(s, c, 1);
		if (*s != 0)
		{
			array[i] = assign_split(s, c);
			if (array[i] == NULL)
				return (NULL);
			i++;
		}
		s = ft_skip_c_or_notc(s, c, 0);
	}
	return (array);
}
