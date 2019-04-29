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

# include "libft/includes/libft.h"
# include <unistd.h>
# include "struct.h"
int					read_and_check(t_node ***rooms);
int					distance(t_node **rooms);

#endif
