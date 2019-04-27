/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:43:56 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 11:16:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		tens;
	char	temp;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
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
		write(fd, &temp, 1);
		n = n - ((n / tens) * tens);
		tens /= 10;
	}
}
