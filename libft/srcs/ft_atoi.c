/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 13:37:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 13:09:17 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int sign;
	int value;
	int i;

	sign = 1;
	value = 0;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' \
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		i++;
	if (*str == '-')
		sign = -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		value = 10 * value + sign * (str[i] - '0');
		i++;
	}
	return (value);
}
