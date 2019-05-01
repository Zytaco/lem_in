
#include "next_move.h"

static int	move_ant(t_node **oc, t_node *from, t_node *to, t_node **previous)
{
	int i;
	int ret;

	from->ants--;
	to->ants++;
	i = 0;
	while (oc[i] != from)
		i++;
	oc[i] = to;
	if (previous != NULL)
		*previous = to;
	return (1);
}

static int	setup(t_node *prev, t_node *from, t_node **lnks, int *i)
{
	int j;
	int prev_d;

	j = 0;
	if (prev == NULL)
		prev_d = from->distance - 1;
	else
		prev_d = prev->distance;
	if (prev != from)
	{
		while (prev != NULL && lnks[j] != prev)
			j++;
	}
	*i = j;
	return (prev_d);
}

/*
** if timer is N then only rooms with distance N - 1 are valid targets.
*/

int			next_move(t_node **oc, t_node *from, t_node **previous, int timer)
{
	int i;
	int	prev_d;
	t_node **lnks;

	lnks = from->links;
	prev_d = setup(*previous, from, lnks, &i);
	while (lnks[i]->distance > prev_d && prev_d <= from->distance + 1 &&
	(lnks[i]->ants < 1 || lnks[i]->start || lnks[i]->end) && prev_d < timer)
	{
		i++;
		if (lnks[i] == NULL)
			i = 0;
		if (lnks[i] == *previous && prev_d == from->distance)
			return (move_ant(oc, from, lnks[i], previous));
		if (lnks[i] == *previous || (*previous == NULL && i == 0))
			prev_d++;
	}
	if (prev_d > from->distance + 1 || prev_d >= timer)
	{
		*previous = NULL;
		return (0);
	}
	return (move_ant(oc, from, lnks[i], previous));
}
