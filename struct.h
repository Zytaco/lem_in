
typedef struct		s_ant
{
	int				timer;
	t_node			*node;
}					t_ant;

typedef	struct		s_node
{
	char			*name;
	bool			end;
	t_ant			**ants;
	struct s_node	**links;
	int				distance;
	int				choke;
}					t_node;
