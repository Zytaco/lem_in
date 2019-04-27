/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:33:30 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 12:20:09 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static char		*ft_itoa_min(void)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * 12);
	str[11] = 0;
	str[10] = '8';
	str[9] = '4';
	str[8] = '6';
	str[7] = '3';
	str[6] = '8';
	str[5] = '4';
	str[4] = '7';
	str[3] = '4';
	str[2] = '1';
	str[1] = '2';
	str[0] = '-';
	return (str);
}

static char		*ft_itoa_len(int n, int len, int sign)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (sign == -1)
		str[0] = '-';
	while (i >= (sign - 1) / -2)
	{
		str[i] = n - ((n / 10) * 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			sign;
	int			len;
	long int	tens;

	sign = 1;
	len = 1;
	if (n == -2147483648)
		return (ft_itoa_min());
	else if (n < 0)
	{
		len++;
		sign = -1;
		n *= -1;
	}
	tens = 10;
	while (tens <= n)
	{
		tens *= 10;
		len++;
	}
	return (ft_itoa_len(n, len, sign));
}
