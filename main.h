/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 16:10:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/26 16:10:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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
