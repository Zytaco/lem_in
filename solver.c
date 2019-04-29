
#include "solver.h"

/*
** given a turn and all nodes having distances is there a one true turn
** so that if that turn doesn't work more turns are needed?
** no.
*/
/*
** The occupied array contains one address per ant to the room that ant is in.
*/

static char	*add_names(char *name1, char *name2, char *walk)
{
	char	*new;
	int		i;

	if (name1 == NULL && name2 == NULL)
	{
		new = ft_strrjoin(walk, "\n");
		ft_strdel(&walk);
	}
	else
	{
		walk = add_space(walk);
		new = ft_strrjoin(walk, "L");
		ft_strdel(&walk);
		walk = ft_strrjoin(new, name1);
		ft_strdel(&new);
		new = ft_strrjoin(walk, "-");
		ft_strdel(&walk);
		walk = ft_strrjoin(new, name2);
		ft_strdel(&new);
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

static int	algo(t_node **oc, int ant, int timer, char *walk)
{
	int i;

	if (timer == -1)
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
	i = 0;
	while (next_move(oc, ant, &i) && !algo(oc, ant + 1, timer, walk))
		undo_move(oc, ant, &i);
	if (i == -1)
		return (0);
	add_move(oc, ant, i, &walk);
	return (1);
}

/*
** j starts at -1 so the following while loop can cycle through all the
** links but also staying put as possible actions.
*/

void		solver(t_node **occupied, char *walk)
{
	int timer;

	timer = occupied[0]->distance;
	while (!algo(occupied, 0, timer, walk))
		timer++;
}
