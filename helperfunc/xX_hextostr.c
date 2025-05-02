/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_hextostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:48:30 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:54:20 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*ft_iszero(void)
{
	char	*str;

	str = malloc((sizeof(char) * 1) + 1);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_smallhextostr(va_list list)
{
	unsigned int	val;
	size_t			i;
	char			*str;

	i = 0;
	val = va_arg(list, unsigned int);
	if (val == 0)
		return (ft_iszero());
	str = ft_sizettohex(val);
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char	*ft_bighextostr(va_list list)
{
	unsigned int	val;
	char			*str;

	val = va_arg(list, unsigned int);
	if (val == 0)
		return (ft_iszero());
	str = ft_sizettohex(val);
	return (str);
}
