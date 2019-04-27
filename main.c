/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 16:09:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/26 16:09:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int main(void)
{
	t_node	**rooms;

	if (!read_and_check(&rooms))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	solver(rooms);
	return (1);
}
