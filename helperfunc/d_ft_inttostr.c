/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ft_inttostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:03:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 00:14:51 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*ft_appendplussign(char *str)
{
	size_t	strlen;
	size_t	i;
	char	*new;

	new = NULL;
	i = 0;
	strlen = ft_strlen(str);
	new = malloc((sizeof(char) * strlen + 1) + 1);
	new[strlen + 1] = '\0';
	new[i++] = '+';
	while (strlen)
	{
		new[i++] = *(str++);
		strlen--;
	}
	free(str - i + 1);
	return (new);
}

static	const char	*ft_returnpercent(const char	*str)
{
	while (*str != '%')
		str--;
	return (++str);
}

char	*d_ft_inttostr(va_list list, const char *str)
{
	char	*i;
	size_t	width;

	i = ft_itoa(va_arg(list, int));
	str = ft_returnpercent(str);
	width = ft_formatspecsizebonus(str, '+');
	if ((width != 0) && (*i != '-'))
		i = ft_appendplussign(i);
	return (i);
}
