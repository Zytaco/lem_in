
#include "distance.h"

/*
** returns 1 only if a room has newly gotten a distance.
*/

static int	surround(t_node *room)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (room->links[i])
	{
		if (room->links[i]->distance == -1)
		{
			ret = 1;
			room->links[i]->distance = room->distance + 1;
		}
		i++;
	}
	return (ret);
}

static int	rooms_with_d(t_node **rooms, int distance)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->distance == distance)
			ret = surround(rooms[i]);
		i++;
	}
	return (ret);
}

/*
** it is important to know that the end room has already received
** it's distance; 0.
** .
** while new rooms receive their distance the function distance
** will make rooms of iteratively greater distance be surrounded
** with rooms of correct distance.
** .
** By working one distance at a time it is guaranteed that all assigned
** distances are correct at any point in the process.
** .
** Then it checks if start is connected to end.
** If not this map is invalid.
*/

int			distance(t_node **rooms)
{
	int i;
	int did_something;
	int distance;

	distance = 0;
	did_something = 1;
	while (did_something)
	{
		did_something = rooms_with_d(rooms, distance);
		distance++;
	}
	if (rooms[0]->distance == -1)
		return (0);
	return (1);
}
