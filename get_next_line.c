/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:36:45 by abao              #+#    #+#             */
/*   Updated: 2018/10/15 19:36:48 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	read_line(char **buf, char *str, int fd)
{
	int			x;
	char		*tmp;

	x = read(fd, str, BUFF_SIZE);
	str[x] = '\0';
	tmp = buf[fd];
	buf[fd] = ft_strjoin(buf[fd], str);
	ft_strdel(&tmp);
	return (x);
}

int	get_end(char **line, int fd, char **buf)
{
	*line = ft_strdup(buf[fd]);
	ft_strdel(&buf[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[255];
	char		str[BUFF_SIZE + 1];
	char		*find;
	int			x;

	x = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	while (x > 0)
	{
		if ((find = ft_strchr(buf[fd], '\n')) != NULL)
		{
			*find = '\0';
			*line = ft_strdup(buf[fd]);
			ft_memmove(buf[fd], find + 1, ft_strlen(find + 1) + 1);
			return (1);
		}
		x = read_line(buf, str, fd);
	}
	if ((x == 0 && (buf[fd] == NULL || buf[fd][0] == '\0')) || (x < 0))
		return (x);
	return (get_end(line, fd, buf));
}
