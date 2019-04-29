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

int	put_in_start(t_node **rooms, int ants)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 0;
	while (rooms[i] && !rooms[i]->start)
		i++;
	if (!rooms[i] || !ants || ants <= 0)
		return (0);
	temp = rooms[0];
	rooms[0] = rooms[i];
	rooms[i] = temp;
	rooms[0]->ants = ants;
	j = 0;
	while (rooms[j] && !rooms[j]->end)
		j++;
	if (!rooms[j])
		return (0);
	rooms[j]->distance = 0;
	temp = rooms[1];
	rooms[1] = rooms[j];
	rooms[j] = temp;
	return (1);
}

int	add_link(t_node *node, t_list *target)
{
	int		i;
	t_node	**new;

	i = 0;
	while (node->links && node->links[i])
		i++;
	new = (t_node**)malloc(sizeof(t_node*) * (i + 2));
	if (new == NULL)
		return (0);
	i = 0;
	while (node->links && node->links[i])
	{
		if (node->links[i] == target)
			return (1);
		new[i] = node->links[i];
		i++;
	}
	new[i] = target;
	new[i + 1] = NULL;
	free(node->links);
	node->links = new;
	return (1);
}

int	make_link(t_node **rooms, char *line)
{
	int i;
	int j;
	int k;

	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = '\0';
	j = 0;
	while (rooms[j] && !strequ(rooms[j]->name, line))
		j++;
	k = 0;
	while (rooms[k] && !strequ(rooms[k]->name, line + i + 1))
		k++;
	if (!rooms[j] || !rooms[k] || j == k)
		return (0);
	add_link(rooms[j], rooms[k]);
	add_link(rooms[k], rooms[j]);
	return (1);
}

int link_check(char *line, t_node **rooms)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}
