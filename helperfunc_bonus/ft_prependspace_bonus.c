/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependspace_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:26:55 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/04 11:44:01 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

static	char	*ft_paddspaces(size_t width, char *str)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(str);
	if (width <= len)
		return (str);
	newstr = malloc((sizeof(char) * width) + 1);
	newstr[width] = '\0';
	while (width)
		newstr[--width] = ' ';
	while (len)
	{
		len--;
		newstr[len] = str[len];
	}
	free(str);
	return (newstr);
}

char	*ft_prependspace(char *stro, const char *str)
{
	size_t	width;
	size_t	numcount;

	if (ft_isdigit(str[0]) == 1 && str[0] != '0')
		width = ft_atoi(&(str[0]));
	else
		width = ft_atoi(&(str[1]));
	numcount = ft_formatspecsize(str);
	if ((str[numcount - 1] == 'c') && (*stro == 0))
		width--;
	stro = ft_paddspaces(width, stro);
	return (stro);
}
