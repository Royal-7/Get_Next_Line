/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:45:03 by abao              #+#    #+#             */
/*   Updated: 2018/09/24 15:52:34 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function replaces every instance of a character in a string with
** one of my choosing. Did I really not already have one like this?
*/

char	*ft_strreplace(char *str, char a, char b)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == a)
			str[x] = b;
		x++;
	}
	return (str);
}
