/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatspecifiersize.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:07:06 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/28 15:57:57 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_formatspecsize(const char *str)
{
	size_t	i;
	size_t	b;
	char	*convspecifier;

	i = 0;
	convspecifier = "cspdiuxX%";
	while (str[i] != '\0')
	{
		b = 0;
		while (b < 10)
		{
			if (str[i + 1] == convspecifier[b++])
				return (i + 2);
		}
		i++;
	}
	return (1);
}

char	ft_isformat(const char *str)
{
	size_t	i;
	size_t	b;
	char	*convspecifier;

	i = 0;
	convspecifier = "cspdiuxX%";
	while (str[i] != '\0')
	{
		b = 0;
		while (b < 10)
		{
			if (str[i] == convspecifier[b++])
				return (str[i]);
		}
		i++;
	}
	return (0);
}

size_t	ft_formatspecsizebonus(const char *str, char b)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == b)
			return (++i);
		i++;
	}
	return (0);
}
