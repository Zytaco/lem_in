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

static void		order_links(t_node **rooms)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 0;
	while (rooms[i])
	{
		j = 0;
		while (j <= 0 || rooms[i]->links[j + 1])
		{
			if (j >= 0 &&
			rooms[i]->links[j]->distance > rooms[i]->links[j + 1]->distance)
			{
				temp = rooms[i]->links[j];
				rooms[i]->links[j] = rooms[i]->links[j + 1];
				rooms[i]->links[j + 1] = temp;
				j--;
			}
			else
				j++;
		}
		i++;
	}
}

static void		free_rooms(t_node ***rooms)
{
	int i;

	i = 0;
	while ((*rooms)[i])
	{
		if ((*rooms)[i]->links)
			free((*rooms)[i]->links);
		(*rooms)[i]->links = NULL;
		free((*rooms)[i]);
		(*rooms)[i] = NULL;
		i++;
	}
	free(*rooms);
	*rooms = NULL;
}

static t_node	*make_occupied(t_node *start)
{
	t_node	**occupied;
	int		i;

	occupied = (t_node**)malloc(sizeof(t_node*) * (start->ants + 1));
	if (occupied == NULL)
		return (NULL);
	while (i < start->ants)
	{
		occupied[i] = start;
		i++;
	}
	occupied[i] = NULL;
	return (occupied);
}

static void		display(char *walk)
{
	int i;

	i = 0;
	while (walk && walk[i])
	{
		write(1, *(walk + i), 1);
		i++;
	}
	if (walk)
		ft_strdel(&walk);
	else
		write(1, "Error\n", 6);
}

int				main(void)
{
	t_node	**rooms;
	t_node	**occupied;
	char	*walk;

	walk = NULL;
	if (!read_and_check(&rooms) || !distance(rooms))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	order_links(rooms);
	occupied = make_occupied(*rooms);
	if (occupied == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	solver(occupied, walk);
	display(walk);
	free_rooms(&rooms);
	return (1);
}
