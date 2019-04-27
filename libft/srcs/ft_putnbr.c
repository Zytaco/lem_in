/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:01:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/06 13:49:18 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int		tens;
	char	temp;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
			write(1, "2147483648", 10);
		if (n == -2147483648)
			return ;
		else
			n *= -1;
	}
	tens = 1;
	while (n != 0 && tens <= n && tens != 1000000000)
		tens *= 10;
	if (!(n >= 1000000000 || n == 0))
		tens /= 10;
	while (tens >= 1)
	{
		temp = (n / tens) + '0';
		write(1, &temp, 1);
		n = n - ((n / tens) * tens);
		tens /= 10;
	}
}
