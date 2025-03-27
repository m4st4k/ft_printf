/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:06:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 03:18:06 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_firstargcheck(const char *str, va_list list, size_t *count)
{
	if (ft_strncmp(str, "c", 1) == 0)
		return (c_ft_chartostr(list, count));
	else if (ft_strncmp(str, "s", 1) == 0)
		return (s_ft_strtostr(list));
	else if (ft_strncmp(str, "p", 1) == 0)
		return (p_ft_ptrtostr(list));
	else if (ft_strncmp(str, "d", 1) == 0)
		return (d_ft_inttostr(list));
	else if (ft_strncmp(str, "i", 1) == 0)
		return (d_ft_inttostr(list));
	else if (ft_strncmp(str, "u", 1) == 0)
		return (u_ft_uninttostr(list));
	else if (ft_strncmp(str, "x", 1) == 0)
		return (ft_smallhextostr(list));
	else if (ft_strncmp(str, "X", 1) == 0)
		return (ft_bighextostr(list));
	else if (ft_strncmp(str, "%", 1) == 0)
		return (ft_perctostr());
/*
	else if (ft_strncmp(str, "%0", 1) == 0)
		return (ft_prependzero(list));
*/
	return (NULL);
}

static	void	generalargcheck(const char *str, va_list list, size_t *count)
{
	size_t	i;
	size_t	val;
	char	*stro;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_strncmp(&(str[i]), "%0", 2) == 0))
		{
			val = ft_checkifnum(&(str[i + 1]));
			i = i + val + 1;
		}
		else if (str[i] == '%')
		{
			stro = ft_firstargcheck(&(str[i + 1]), list, count);
			ft_putstr_fd(stro, 1);
			(*count) += (size_t)ft_strlen(stro);
			free(stro);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			(*count)++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	size_t	*count;
	va_list	list;

	len = 0;
	count = &len;
	va_start(list, str);
	generalargcheck(str, list, count);
	va_end(list);
	return (len);
}
/*
int	main(void)
{
	printf("Return: %d\n", printf("%x\n", 0));
	printf("Return me: %d\n", ft_printf("%x\n", 0));
	//printf("%s", ft_sizettohex(a));
	return (0);
}
*/
