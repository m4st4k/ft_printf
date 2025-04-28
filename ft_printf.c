/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:06:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/28 22:18:07 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include "helperfunc_bonus/ft_helperfunc_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_firstargcheck_bonus(const char *str, va_list list, size_t *count)
{
	size_t	numcount;
	char	*stro;

	numcount = ft_formatspecsize(str);
	stro = ft_firstargcheck(&(str[numcount - 1]), list, count);
	return (stro);
	if (ft_strncmp(str, "-", 1) == 0)
		return (ft_prependspace(stro, str));
	else if (ft_strncmp(str, "#", 1) == 0)
                return (ft_hashtag(stro, str[numcount - 1]));
	else if (ft_strncmp(str, "0", 1) == 0)
		return (ft_prependzero(stro, str));
	else if (ft_strncmp(str, " ", 1) == 0)
		return (ft_space(stro, str));
	else if (ft_strncmp(str, ".", 1) == 0)
		return (ft_prependzero(stro, str));
	else if (ft_isdigit(str[0]) == 1 && str[0] != '0')
		return (ft_prependspace(stro, str));
	return (ft_perctostr());
}

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
	return (NULL);
}

static	void	ft_defaultcheck(const char *str, va_list list, size_t *count)
{
	size_t	i;
	char	*stro;

	i = 0;
	stro = ft_firstargcheck(&(str[i + 1]), list, count);
	if (stro == NULL)
		stro = ft_firstargcheck_bonus(&(str[i + 1]), list, count);
	ft_putstr_fd(stro, 1);
	(*count) += (size_t)ft_strlen(stro);
	free(stro);
}

static	void	generalargcheck(const char *str, va_list list, size_t *count)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_defaultcheck(&(str[i]), list, count);
			i += ft_formatspecsize(&(str[i]));
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

int	main(void)
{
	printf("\nReturn: %d\n", printf("%--90.11i", 1218643716));
	printf("\nReturn me: %d\n", ft_printf("%--90.11i", 1218643716));
	return (0);
}
