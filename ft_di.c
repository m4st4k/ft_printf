/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:48:03 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/15 21:39:08 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static	size_t	ft_sizeunsgin(unsigned int val)
{
	size_t	len;

	len = 0;
	while (val)
	{
		val = val / 10;
		len++;
	}
	return (len);
}

int	ft_printint(int val)
{
	char	*t;
	size_t	len;

	len = 0;
	t = ft_itoa(val);
	len += ft_printstr(t);
	free(t);
	t = NULL;
	return (len);
}

int	ft_printunint(unsigned int val)
{
	char	*str;
	size_t	vallen;
	size_t	len;

	if (!val)
		return (ft_printstr("0"));
	len = 0;
	vallen = ft_sizeunsgin(val);
	str = malloc(vallen + 1);
	str[vallen] = '\0';
	while (vallen)
	{
		str[--vallen] = (val % 10) + '0';
		val = val / 10;
	}
	len += ft_printstr(str);
	free(str);
	str = NULL;
	return (len);
}
