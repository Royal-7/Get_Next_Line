/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:39:15 by abao              #+#    #+#             */
/*   Updated: 2018/10/06 16:53:20 by abao             ###   ########.fr       */
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

int		function(int fd, char **buf, static char *a)
{
	char	buffer[BUFF_SIZE + 1];
	char 	*tmp;
	int		x;

	ft_strclr(buffer);
	tmp = ft_strnew(BUFF_SIZE + 1);
	while ((x = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[x] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if ((a = ft_strchr(buffer, '\n')) != NULL)
		{
			ft_strreplace(tmp, '\n', '\0');
			break ;
		}
		ft_strclr(buffer);
	}
	*buf = tmp;
	printf("buf = %s\n", *buf);
	free(tmp);
	return (x);
}

int		get_next_line(const int fd, char **line)
{
	static char	*a;
	char	*buf;
	int		x;

	if (fd < 0 || line == NULL)
		return (-1);
	x = function(fd, &buf, a);
	*line = buf;
	if (x == 0 && ft_strchr(*line, '\0') != NULL)
		return (0);
	if (x == -1)
		return (-1);
	return (1);
}
