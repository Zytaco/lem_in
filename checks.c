/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 16:39:25 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/27 16:39:25 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int	int_check(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

int	comment_check(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int	room_check(char *line)
{
	if (*line == '#' || *line == 'L' || *line == ' ')
		return (0);
	while (*line != ' ' && *line != '\0')
		line++;
	if (*line == ' ')
		line++;
	else
		return (0);
	if (!('0' <= *line && *line <= '9'))
		return (0);
	while ('0' <= *line && *line <= '9')
		line++;
	if (*line == ' ')
		line++;
	else
		return (0);
	if (!('0' <= *line && *line <= '9'))
		return (0);
	while ('0' <= *line && *line <= '9')
		line++;
	if (*line == '\0')
		return (1);
	return (0);
}

int	start_end_check(char *line, int *start_end)
{
	if (ft_strncmp(line, "##start", 8) == 0)
	{
		*start_end = 1;
		return (0);
	}
	else if (ft_strncmp(line, "##end", 8) == 0)
	{
		*start_end = 2;
		return (0);
	}
	else
	{
		*start_end = 0;
		return (1);
	}
}
