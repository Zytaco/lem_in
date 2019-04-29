/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_and_check.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 12:57:20 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/27 12:58:51 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_AND_CHECK_H
# define READ_AND_CHECK_H

# include "libft/includes/libft.h"
# include <unistd.h>
# include "struct.h"
int					int_check(char *s);
int					comment_check(char *line);
int					room_check(char *line);
int					start_end_check(char *line, int *start_end);
int					put_in_start(t_node **rooms, int ants);

#endif
