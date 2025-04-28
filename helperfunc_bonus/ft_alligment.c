/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alligment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:13:09 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/07 16:30:54 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	*rightalignment(char *str)
{
	size_t	i;
	size_t	len;
	size_t	spacecount;
	char	*stro;

	i = 0;
	spacecount = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (str);
	stro = malloc((sizeof(char) * len) + 1);
	stro[len] = '\0';
	while (len)
	{
		if (str[--len] == ' ')
			stro[spacecount++] = ' ';
		else
			break ;
	}
	i = 0;
	while (i < (len + 1))
		stro[spacecount++] = str[i++];
	return (stro);
}
/*
char	*leftalignment(char *str)
{

}
*/
