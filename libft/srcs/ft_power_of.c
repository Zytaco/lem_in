/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power_of.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:22:33 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 14:36:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_power_of(int base, unsigned int power)
{
	int result;

	if (base == 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		if (2147483647 / base > result)
			return (0);
		if (-2147483648 / base < result)
			return (0);
		result *= base;
		power--;
	}
	return (result);
}
