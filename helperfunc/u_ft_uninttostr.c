/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_ft_uninttostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:14:09 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:55:55 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	size_t	ft_divunsigbase10(unsigned int val)
{
	size_t	i;

	i = 0;
	while (val)
	{
		val /= 10;
		i++;
	}
	return (i);
}

static	char	*ft_iszero(void)
{
	char	*str;

	str = malloc((sizeof(char) * 1) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*u_ft_uninttostr(va_list list)
{
	unsigned int	val;
	size_t			len;
	char			*str;

	val = va_arg(list, unsigned int);
	len = ft_divunsigbase10(val);
	if (len == 0)
		return (ft_iszero());
	str = malloc((sizeof(char) * len) + 1);
	str[len] = '\0';
	while (len)
	{
		--len;
		str[len] = (val % 10) + '0';
		val /= 10;
	}
	return (str);
}
