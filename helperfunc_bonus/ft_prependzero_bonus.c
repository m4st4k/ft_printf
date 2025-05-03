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

static	char	*ft_paddzeros_zero(size_t width, char *stro)
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
		if (*stro == '-' || *stro == '+')
			temp[i++] = *stro;
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

static	char	*ft_paddzeros_dot(size_t width, char *stro)
{
	size_t	strlen;

	strlen = ft_strlen(stro);
	while (width < strlen)
		stro[--strlen] = '\0';
	return (stro);
}

char	*ft_prependzero_dot(char *stro, const char *str)
{
	int		width;
	size_t	numcount;
	size_t	start;
	char	*newstr;

	numcount = ft_formatspecsize(str);
	start = ft_formatspecsizebonus(str, '.');
	width = ft_atoi(str + start);
	if (width < 0)
		width = width * -1;
	if (str[numcount - 1] == 's')
		return (ft_paddzeros_dot(width, stro));
	if (*stro == '-')
		width++;
	if (*stro == '0' && str[numcount - 1] != 's' && width == 0)
	{
		stro[0] = '\0';
		return (stro);
	}
	newstr = ft_paddzeros_zero(width, stro);
	return (newstr);
}

char	*ft_prependzero_zero(char *stro, const char *str)
{
	int		width;
	char	*newstr;

	width = ft_atoi(str);
	if (width < 0)
		width = width * -1;
	newstr = ft_paddzeros_zero(width, stro);
	return (newstr);
}
