/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   links.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 17:16:11 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/27 17:16:12 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKS_H
# define LINKS_H

# include "libft/includes/libft.h"
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
