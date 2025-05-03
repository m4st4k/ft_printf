/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_chartostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:58:32 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/03 13:17:02 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	const char	*ft_returnpercent(const char	*str)
{
	while (*str != '%')
		str--;
	return (++str);
}

char	*c_ft_chartostr(va_list list, size_t *count, const char *str)
{
	char	*new;
	char	chr;
	int		width;

	chr = va_arg(list, int);
	new = malloc(sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	str = ft_returnpercent(str);
	width = ft_atoi(str);
	if (chr == 0 && width <= 0)
	{
		write(1, &chr, 1);
		(*count)++;
	}
	new[0] = chr;
	new[1] = '\0';
	return (new);
}
