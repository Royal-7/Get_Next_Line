/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:39:15 by abao              #+#    #+#             */
/*   Updated: 2018/09/24 17:40:00 by abao             ###   ########.fr       */
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

int	get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*newline;
	int		x;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = malloc(sizeof(char) * BUFF_SIZE);
	while ((x = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[x] = '\0';
		*line = ft_strjoin(*line, buf);
		newline = ft_strchr(buf, '\n');
		if (newline != NULL)
		{
			ft_strreplace(*line, '\n', '\0');
			break ;
		}
		ft_strclr(buf);
	}
	if (x == 0)
		return (0);
	if (x == -1)
		return (-1);
	return (1);
}
