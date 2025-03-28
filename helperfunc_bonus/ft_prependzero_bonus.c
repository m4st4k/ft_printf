/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependzero_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:35:55 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/28 02:29:26 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
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

char	*ft_prependzero(va_list list, const char *str, size_t *count)
{
	size_t	width;
	size_t	numcount;
	char	*stro;
	char	*newstr;

	width = ft_atoi(str);
	numcount = ft_checkifnum(str);
	stro = ft_firstargcheck(&(str[numcount]), list, count);
	newstr = ft_paddzeros(width, stro);
	return (newstr);
}
