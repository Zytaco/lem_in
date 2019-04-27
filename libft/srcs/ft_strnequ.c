/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:02:15 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:33:29 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 == (char*)0 && s2 == (char*)0)
		return (0);
	if (s1 == (char*)0)
		return (-1);
	if (s2 == (char*)0)
		return (1);
	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i + 1 < n)
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
