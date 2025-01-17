/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:00:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/12 14:56:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as == (char**)0 || as[0] == (char*)0)
		return ;
	free(&as[0][0]);
	as[0] = (void*)0;
}
