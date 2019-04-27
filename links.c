/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   links.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 17:16:06 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/27 17:16:06 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "links.h"

int link_check(char *line, t_node **rooms)
{
	int i;
	int j;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	j = 0;
	while (rooms[j] != NULL && ft_strncmp(rooms[j]->name, line, i) != 0)
		j++;
	if (rooms[j] == NULL)
		return (0);
	
}
