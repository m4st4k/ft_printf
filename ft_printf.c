/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:06:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/13 14:46:24 by dbriant          ###   ########.fr       */
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

static	int	ft_printstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static	int	ft_printint(int val)
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

static	int	ft_firstargcheck(const char *str, va_list list, size_t *count)
{
	if (ft_strncmp(str, "%c", 2) == 0)
		ft_printchar(count, va_arg(list, int));
	if (ft_strncmp(str, "%s", 2) == 0)
		*count += ft_printstr((char *)va_arg(list, char *));
	if (ft_strncmp(str, "%p", 2) == 0)
		*count += ft_printptr(va_arg(list, void *));
	if (ft_strncmp(str, "%d", 2) == 0)
		*count += ft_printint(va_arg(list, int));
	if (ft_strncmp(str, "%i", 2) == 0)
		*count += ft_printint(va_arg(list, int));
	if (ft_strncmp(str, "%x", 2) == 0)
		*count += ft_inttohexstr(va_arg(list, unsigned int), 0);
	if (ft_strncmp(str, "%X", 2) == 0)
		*count += ft_inttohexstr(va_arg(list, unsigned int), 1);
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
			i += ft_firstargcheck(&(str[i]), list, count);
		else
			i += ft_printchar(count, str[i]);
	}
	va_end(list);
	return (len);
}
/*
int	main(void)
{
	printf("%i\n", 010);
	ft_printf("%i\n", 010);
	return (0);
}
*/
