/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_and_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 12:51:05 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/27 12:51:06 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_and_check.h"

static int	make_ants(char *line, t_ant ***ants)
{
	int n;
	int i;

	n = ft_atoi(line);
	*ants = (t_ant**)malloc(sizeof(t_ant*) * (n + 1));
	if (*ants == NULL)
		return (0);
	(*ants)[n] = NULL;
	i = 0;
	while (i < n)
	{
		(*ants)[i] = (t_ant*)malloc(sizeof(t_ant));
		if ((*ants)[i] == NULL)
			return (0);
		(*ants)[i]->timer = 1;
		i++;
	}
	return (1);
}

static t_node	*make_room(char *name, int x, int y, int start_end)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->x = x;
	new->y = y;
	new->start = 0;
	if (start_end == 1)
		new->start = 1;
	new->end = 0;
	if (start_end == 2)
		new->end = 1;
	new->number_of_ants = 0;
	new->ants = NULL;
	new->links = NULL;
	new->distance = -1;
	new->choke = -1;
	return (new);
}

static int	new_room(t_node **new, int i, char *line, int start_end)
{
	int		j;
	int		x;
	int		y;
	char	*name;

	j = 0;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	name = ft_strnew(j);
	ft_strncpy(name, line, j);
	j++;
	x = ft_atoi(line + j);
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	j++;
	y = ft_atoi(line + j);
	new[i] = make_room(name, x, y, start_end);
	if (new[i] == NULL)
		return (0);
	return (1);
}

static int	make_rooms(t_node ***rooms, char *line, int start_end)
{
	static int	len = 0;
	t_node		**new;
	int			i;

	len++;
	new = (t_node**)malloc(sizeof(t_node*) * (len + 1));
	new[len] = NULL;
	if (new == NULL)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		new[i] = (*rooms)[i];
		i++;
	}
	if (len > 1)
		free(*rooms);
	*rooms = new;
	if (!new_room(new, i, line, start_end))
		return (0);
	return (1);
}

int			read_and_check(t_node ***rooms)
{
	char	*line;
	t_ant	**ants;
	int		start_end;

	line = NULL;
	while (get_next_line(0, &line) && comment_check(line))
		*rooms = NULL;
	if (read(0, line, 0) < 0 || !int_check(line) || !make_ants(line, &ants))
		return (0);
	start_end = 0;
	while (get_next_line(0, &line) && !start_end_check(line, &start_end)
	&& room_check(line) && !comment_check(line))
	{
		if (!make_rooms(rooms, line, start_end))
			return (0);
	}
	while(get_next_line(0, &line) && !comment_check(line) &&
	link_check(line, *rooms))
	{
		if (make_link(*rooms, line))
			return (0);
	}
	if (get_next_line(0, &line) != 0 || put_in_start(rooms, ants))
		return (0);
	return (1);
}
