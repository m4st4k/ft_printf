/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:13:49 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/21 09:56:17 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static	int	ft_checkifnum(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isdigit((int)(str[i])) == 1)
		i++;
	return (i);
}

int	ft_bonusargcheck(const char *str, va_list list, size_t *count)
{
	size_t	i;
	int	val;

	i = ft_checkifnum(str);
	val = ft_atoi(str);
	while (--val)
	{
		write(1, "0", 1);
		(*count)++;
	}
	ft_firstargcheck(str + i, list, count);
	//printf("Val: %ld", i);
	return (i + 3);
}
