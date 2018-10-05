/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:39:15 by abao              #+#    #+#             */
/*   Updated: 2018/10/04 19:25:22 by abao             ###   ########.fr       */
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

int		find_return(char *tmp, char **line)
{
	char	*tmp2;
	int		len;

	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	if (tmp[len] == '\n')
	{
		*line = ft_strsub(tmp, 0, len);
		tmp2 = ft_strdup(tmp + len + 1);
		free(tmp);
		tmp = tmp2;
		if (tmp[0] == '\0')
			ft_strdel(&tmp);
	}
//	else if (tmp[len] == '\0')
//	{
//		if (x == BUFF_SIZE)
//			return (get_next_line(fd, line));
//		*line = ft_strdup(tmp);
//		ft_strdel(&tmp);
//	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		x;
	int		mark;
	char	*tmp;
//	char	*tmp2;

	mark = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE);
	while ((x = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[x] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(buf, '\n') != NULL)
		{
			ft_strreplace(tmp, '\n', '\0');
			break ;
		}
		ft_strclr(buf);
		mark = 1;
	}
	*line = tmp;
	if (x == 0 && ft_strchr(*line, '\0') != NULL && mark != 1)
		return (0);
	if (x == -1)
		return (-1);
	return (find_return(tmp, line));
}
