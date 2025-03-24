/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:06:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/21 19:52:18 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static	int	ft_printchar(size_t *count, char c)
{
	write(1, &c, 1);
	(*count)++;
	return (1);
}

int	ft_printstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_firstargcheck(const char *str, va_list list, size_t *count)
{
	if (ft_strncmp(str, "c", 1) == 0)
		ft_printchar(count, va_arg(list, int));
	else if (ft_strncmp(str, "s", 1) == 0)
		*count += ft_printstr((char *)va_arg(list, char *));
	else if (ft_strncmp(str, "p", 1) == 0)
		*count += ft_printptr(va_arg(list, void *));
	else if (ft_strncmp(str, "d", 1) == 0)
		*count += ft_printint(va_arg(list, int));
	else if (ft_strncmp(str, "i", 1) == 0)
		*count += ft_printint(va_arg(list, int));
	else if (ft_strncmp(str, "u", 1) == 0)
		*count += ft_printunint(va_arg(list, unsigned int));
	else if (ft_strncmp(str, "x", 1) == 0)
		*count += ft_inttohexstr(va_arg(list, unsigned int), 0);
	else if (ft_strncmp(str, "X", 1) == 0)
		*count += ft_inttohexstr(va_arg(list, unsigned int), 1);
	else if (ft_strncmp(str, "%", 1) == 0)
		ft_printchar(count, '%');
	else if (ft_strncmp(str, "0", 1) == 0)
                return (ft_bonusargcheck(str, list, count));
	return (2);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	size_t	*count;
	va_list	list;

	len = 0;
	count = &len;
	i = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i += ft_firstargcheck(&(str[i + 1]), list, count);
		else
			i += ft_printchar(count, str[i]);
	}
	va_end(list);
	return (len);
}
/*
int	main(void)
{
	printf("Return: %d\n", printf("%01d\n", -1));
	printf("Return me: %d\n", ft_printf("%01d\n", -1));
	return (0);
}
*/
