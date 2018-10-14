/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:58:36 by abao              #+#    #+#             */
/*   Updated: 2018/10/14 15:27:36 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		read_line(const int fd, int *x, char **buf)
{
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;
	
	*x = read(fd, tmp, BUFF_SIZE);
	tmp[*x] = '\0';
	tmp2 = *buf;
	*buf = ft_strjoin(*buf, tmp);
	ft_strdel(&tmp2);
	return (*x);
}

int		get_end(char **line, char *buf)
{
	if (!(*line = ft_strdup(buf)))
		return (-1);
	ft_strclr(buf);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf = "";
	int			x;
	char		*find;

	x = 1;
	if (fd < 0 || line == NULL || (buf[0] == '\0' && (!(buf = ft_strnew(0)))))
		return (-1);
	while (x > 0)
	{
		if ((find = ft_strchr(buf, '\n')) != NULL)
		{
			*find = '\0';
			if (!(*line = ft_strdup(buf)))
				return (1);
			ft_memmove(buf, find + 1, ft_strlen(find + 1) + 1);
			return (1);
		}
		x = read_line(fd, &x, &buf);
	}
	ft_strdel(&find);
	if (x == 0 && (ft_strlen(buf) > 0))
		x = get_end(line, buf);
	return (x);
}
