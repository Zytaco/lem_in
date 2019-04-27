/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:09:44 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 13:44:41 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return (s + i);
	else
		return ((void*)0);
}
