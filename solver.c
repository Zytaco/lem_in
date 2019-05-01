
#include "solver.h"

/*
** given a turn and all nodes having distances is there a one true turn
** so that if that turn doesn't work more turns are needed?
** no.
*/
/*
** The occupied array contains one address per ant to the room that ant is in.
*/

static int	move_ant(t_node **oc, t_node *from, t_node *to)
{
	int i;
	int ret;

	from->ants--;
	to->ants++;
	i = 0;
	while (oc[i] != from)
		i++;
	oc[i] = to;
	return (1);
}

static char	*add_names(char *name1, char *name2, char *walk)
{
	char	*temp;
	int		i;

	if (name1 == NULL && name2 == NULL)
	{
		temp = ft_strjoin("\n", walk);
		ft_strdel(&walk);
		walk = temp;
	}
	else
	{
		temp = ft_strjoin(name2, walk);
		ft_strdel(&walk);
		temp = ft_strjoin("-", walk);
		ft_strdel(&walk);
		walk = ft_strjoin(name1, temp);
		ft_strdel(&temp);
		walk = ft_strjoin("L", temp);
		ft_strdel(&temp);
	}
	return (walk);
}

static void	add_move(t_node **oc, int ant, int i, char **walk)
{
	int k;

	if (!oc[ant + 1])
		walk = add_names(NULL, NULL, *walk);
	k = 0;
	while (oc[ant]->links[k]->distance <= oc[ant]->distance)
	{
		if (i == k)
		{
			walk = add_names(oc[ant]->name, oc[ant]->links[k]->name, *walk);
			return ;
		}
		k++;
	}
	if (i == k)
		return ;
	while (oc[ant]->links[k])
	{
		if (i == k - 1)
		{
			walk = add_names(oc[ant]->name, oc[ant]->links[k]->name, *walk);
			return ;
		}
		k++;
	}
}

/*
** if timer == 0 then time has ran out and algo should've returned 1 already.
** previous is used to track what the previous move was.
** undo is the initial node before the ant tries moving to other rooms.
*/

static int	algo(t_node **oc, int ant, int timer, char *walk)
{
	t_node *previous;
	t_node *undo;

	if (timer == 0)
	{
		if (oc[ant - 1]->distance == 0)
			return (1);
		return (0);
	}
	if (!oc[ant])
	{
		ant = 0;
		timer--;
	}
	undo = oc[ant];
	previous = NULL;
	while (next_move(oc, oc[ant], &previous, timer) && !algo(oc, ant + 1, timer, walk))
		move_ant(oc, oc[ant], undo);
	if (previous == NULL)
		return (0);
	add_move(oc, ant, &previous, &walk);
	return (1);
}

void		solver(t_node **occupied, char *walk)
{
	int timer;

	timer = occupied[0]->distance;
	if (timer == 0)
	{
		walk = "";
		return ;
	}
	while (!algo(occupied, 0, timer, walk))
		timer++;
}
