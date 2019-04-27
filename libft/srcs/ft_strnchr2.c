/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnchr2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 10:50:16 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/01 11:49:40 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnchr2(const char *s, int c1, int c2)
{
	long unsigned int i;

	if (s == (void*)0)
		return (-2);
	i = 0;
	while (s[i] && s[i] != (char)c1 && s[i] != (char)c2)
		i++;
	if (s[i] != (char)c1 && s[i] != (char)c2)
		return (-1);
	else
		return (i);
}
