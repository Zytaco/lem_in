/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:41:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/22 16:29:24 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnchr(const char *s, int c)
{
	long unsigned int i;

	if (s == (void*)0)
		return (-2);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	else
		return (i);
}
