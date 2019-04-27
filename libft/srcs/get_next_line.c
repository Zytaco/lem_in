/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:42:50 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/03/12 15:14:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** assign_line puts buf in line and stores any excess in to_be_read.
** buf can be to_be_read.
** uses rd as the length of buf.
** protection against reading error happens here.
** return of -1, 0, or 1 indicates reading is done, 2 means it's not.
** due to the length of buf no more than BUFF_SIZE - 1 chars will be
** copied into to_be_read.
*/

static int		assign_line(char **line, char *buf, long int rd, \
					char *to_be_read)
{
	char	*temp;
	int		eol;

	if (rd < 0)
		return (-1);
	temp = *line;
	*line = ft_strjoin(*line, buf);
	ft_strdel(&temp);
	if (*line == NULL)
		return (-1);
	eol = ft_strnchr(*line, '\n');
	if (eol >= 0 || (rd == 0 && **line != '\0'))
	{
		line[0][eol] = '\0';
		if (eol >= 0)
			ft_strcpy(to_be_read, (line[0] + eol + 1));
		return (1);
	}
	else if (rd < BUFF_SIZE)
		return (0);
	return (2);
}

/*
** buf_modification takes buf and adds a newline at the end if there
** isn't one already. rd is the length of buf.
** requires buf being of size BUFF_SIZE + 1 for a terminating character and in
** case of rd < BUFF_SIZE a newline and a terminating character.
*/

static void		buf_modification(char *buf, long int rd)
{
	if (rd < BUFF_SIZE && rd > 0 && buf[rd - 1] != '\n')
	{
		buf[rd] = '\n';
		buf[rd + 1] = '\0';
	}
	else
		buf[rd] = '\0';
}

/*
** get_next_line checks input and passes to_be_read (tb_rd) to be put in line
** if there is anything in tb_rd.
** checks for blatant input error.
** reads from fd into buf, passes buf to buf_modification then assign_line.
** doesn't work with multiple fd.
** tb_rd is static to store unread portions of buf
*/

int				get_next_line(const int fd, char **line)
{
	static char		*tb_rd = NULL;
	char			*buf;
	long int		rd;
	int				returned;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	ft_strdel(line);
	if (tb_rd == NULL)
		tb_rd = ft_strnew(BUFF_SIZE);
	buf = ft_strnew(BUFF_SIZE);
	returned = 2;
	if (tb_rd[0] != '\0')
		returned = assign_line(line, tb_rd, (int)ft_strlen(tb_rd), tb_rd);
	returned = (returned == 0 ? 2 : returned);
	while (returned == 2)
	{
		rd = (long int)read(fd, buf, BUFF_SIZE);
		buf_modification(buf, rd);
		returned = assign_line(line, buf, rd, tb_rd);
	}
	ft_strdel(&buf);
	buf = NULL;
	return (returned);
}
