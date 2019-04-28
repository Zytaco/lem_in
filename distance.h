
#ifndef DISTANCE_H
# define DISTANCE_H

typedef struct		s_ant
{
	int				timer;
}					t_ant;
typedef	struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	t_ant			**ants;
	struct s_node	**links;
	int				distance;
	int				choke;
}					t_node;

#endif
