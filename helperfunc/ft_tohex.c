/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:41:58 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:59:15 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	size_t	ft_divbase16(size_t val)
{
	size_t	i;

	i = 0;
	while (val)
	{
		val /= 16;
		i++;
	}
	return (i);
}

static	char	*ft_byteparser(char *str, size_t val, size_t length)
{
	while (length)
	{
		str[--length] = (val % 16) + '0';
		if (str[length] > '9')
			str[length] = str[length] + 7;
		val /= 16;
	}
	return (str);
}

char	*ft_sizettohex(size_t val)
{
	char	*str;
	size_t	i;

	i = ft_divbase16(val);
	str = malloc((sizeof(char) * i) + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	str = ft_byteparser(str, val, i);
	return (str);
}
