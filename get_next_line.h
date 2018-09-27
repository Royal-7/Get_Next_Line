/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:49:40 by abao              #+#    #+#             */
/*   Updated: 2018/09/27 13:17:49 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);
char	*test_newline(char *buf, char **line);

#endif
