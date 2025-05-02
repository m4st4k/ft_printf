/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_chartostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:58:32 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:58:03 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*c_ft_chartostr(va_list list, size_t *count)
{
	char	*str;
	char	chr;

	chr = va_arg(list, int);
	str = malloc(sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	if (chr == 0)
	{
		write(1, &chr, 1);
		(*count)++;
	}
	str[0] = chr;
	str[1] = '\0';
	return (str);
}
