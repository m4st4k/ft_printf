/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependzero_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:35:55 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/04 11:43:43 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include "ft_helperfunc_bonus.h"
#include <stdlib.h>
#include <stdarg.h>

static	void	ft_ifstrneg(char *temp, char *stro, size_t i)
{
	if (*stro == '-')
		stro++;
	while (*stro != '\0')
	{
		temp[i++] = *stro;
		stro++;
	}
}

static	char	*ft_paddzeros(size_t width, char *stro)
{
	size_t	strolen;
	size_t	amountofzeros;
	size_t	i;
	char	*temp;

	i = 0;
	strolen = ft_strlen(stro);
	if (width > strolen)
	{
		temp = malloc((sizeof(char) * width) + 1);
		temp[width] = '\0';
		amountofzeros = width - strolen;
		if (*stro == '-')
			temp[i++] = '-';
		while (amountofzeros)
		{
			temp[i++] = '0';
			amountofzeros--;
		}
		ft_ifstrneg(temp, stro, i);
		free(stro);
		return (temp);
	}
	return (stro);
}

char	*ft_prependzero(char *stro, const char *str)
{
	size_t	width;
	size_t	numcount;
	char	*newstr;

	if (str[1] == '-')
		return (ft_prependspace(stro, &(str[1])));
	if (str[0] == '.')
		width = ft_atoi(&(str[1]));
	else
		width = ft_atoi(str);
	numcount = ft_formatspecsize(str);
	if ((str[numcount - 1] == 's') && (*stro == '\0'))
		width = 1;
	newstr = ft_paddzeros(width, stro);
	return (newstr);
}
