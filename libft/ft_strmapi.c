/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:06:21 by abao              #+#    #+#             */
/*   Updated: 2018/07/21 20:35:51 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	char	*new;

	if (!s || !f)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	x = 0;
	while (s[x] != '\0')
	{
		new[x] = (*f)(x, s[x]);
		x++;
	}
	new[x] = '\0';
	return (new);
}
