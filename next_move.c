
#include "next_move.h"

static int	check_move(t_node **oc, t_node *from, t_node *to)
{
	int i;

	i = 0;
	while (oc[i] && oc[i] != from)
		i++;
	if (oc[i] == NULL)
		return (0);
	if (to->end == 0 && to->start == 0 && to->ants > 0)
		return (0);
	return (1);
}

static int	move_ant(t_node **oc, t_node *from, t_node *to)
{
	int i;
	int ret;

	if (!check_move(oc, from, to))
		return (0);
	from->ants--;
	to->ants++;
	i = 0;
	while (oc[i] != from)
		i++;
	oc[i] = to;
	return (1);
}

void		undo_move(t_node **oc, int ant, int *j)
{
	int i;

	i = 0;
	while (oc[ant]->links[i]->distance <= oc[ant]->distance)
	{
		if (*j == i)
		{
			move_ant(oc, oc[ant]->links[i], oc[ant]);
			return ;
		}
		i++;
	}
	if (*j == i)
		return ;
	while (oc[ant]->links[i])
	{
		if (*j == i - 1)
		{
			move_ant(oc, oc[ant]->links[i], oc[ant]);
			return ;
		}
		i++;
	}
	(*j)++;
}

int			next_move(t_node **oc, int ant, int *j)
{
	int i;

	i = 0;
	while (oc[ant]->links[i]->distance <= oc[ant]->distance)
	{
		if (*j == i)
			return (move_ant(oc, oc[ant], oc[ant]->links[i]));
		i++;
	}
	if (*j == i)
		return (1);
	while (oc[ant]->links[i])
	{
		if (*j == i - 1)
			return (move_ant(oc, oc[ant], oc[ant]->links[i]));
		i++;
	}
	(*j) = -1;
	return (0);
}