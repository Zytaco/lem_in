/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 07:28:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 13:02:16 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	temp1;
	unsigned char	temp2;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	temp1 = (unsigned char)s1[i];
	temp2 = (unsigned char)s2[i];
	return (temp1 - temp2);
}
