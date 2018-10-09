/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:01:45 by abao              #+#    #+#             */
/*   Updated: 2018/10/08 19:09:31 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Read from file descriptor until either new line or end of file.
** Param: int file descriptor, char** to save the line.
** Return: 1 if line has been read, 0 for EOF, -1 for error.
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*read_file(int fd, char *buf, int *x)
{
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;

	*x = read(fd, tmp, BUFF_SIZE);
	tmp[*x] = '\0';
	tmp2 = buf;
	if (!(buf = ft_strjoin(buf, tmp)))
		return (NULL);
	ft_strdel(&tmp2);
	return (buf);
}

int		ft_get_end(char **line, char *buf)
{
	if (!(*line = ft_strdup(buf)))
		return (-1);
	ft_strclr(buf);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf = "";
	char		*str;
	int			x;

	x = 1;
	if (!line || fd < 0 || (buf[0] == '\0' && (!(buf = ft_strnew(0)))))
		return (-1);
	while (x > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = '\0';
			if (!(*line = ft_strdup(buf)))
				return (-1);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		buf = read_file(fd, buf, &x);
	}
	ft_strdel(&str);
	if (x == 0 && ft_strlen(buf))
		x = ft_get_end(line, buf);
	return (x);
}
