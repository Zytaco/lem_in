
#ifndef STRUCT_H
# define STRUCT_H

typedef	struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	int				ants;
	struct s_node	**links;
	int				distance;
}					t_node;

#endif
