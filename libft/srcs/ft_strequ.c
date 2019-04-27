/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:45:50 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 14:30:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (s1 == (char*)0 && s2 == (char*)0)
		return (0);
	if (s1 == (char*)0)
		return (-1);
	if (s2 == (char*)0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
