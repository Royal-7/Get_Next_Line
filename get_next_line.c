/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:39:15 by abao              #+#    #+#             */
/*   Updated: 2018/09/27 13:52:29 by abao             ###   ########.fr       */
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

char	*test_newline(char *buf, char **line)
{
	char	*newline;

	newline = ft_strchr(buf, '\n');
	if (newline != NULL)
	{
		ft_strreplace(*line, '\n', '\0');
		return (newline);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		x;
	int		mark;
//	char	*tmp;

	mark = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = (char*)malloc(sizeof(char) * BUFF_SIZE);
	while ((x = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[x] = '\0';
		*line = ft_strjoin(*line, buf);
//		tmp = *line; //These three lines keep fucking up everything
//		free(*line); //If I don't free it, it leaks
//		*line = tmp; //If I do, it doesn't work
		if (test_newline(buf, line) != NULL)
			break ;
		ft_strclr(buf);
		mark = 1;
	}
	if (x == 0 && ft_strchr(*line, '\0') != NULL && mark != 1)
		return (0);
	if (x == -1)
		return (-1);
	return (1);
}
