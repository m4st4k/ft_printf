/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:06:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/02 14:31:09 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_firstargcheck_bonus(const char *str, va_list list, size_t *count)
{
	size_t	numcount;
	char	*stro;

	numcount = ft_formatspecsize(str);
	stro = ft_firstargcheck(&(str[numcount - 1]), list, count);
	if (ft_memchr(str, '.', numcount - 1))
		stro = ft_prependzero_dot(stro, str);
	if (ft_memchr(str, '-', numcount - 1))
		stro = ft_prependspace_minus(stro, str);
	if ((*str == '0') && ((ft_memchr(str, '-', numcount - 1) == NULL)
			&& (ft_memchr(str, '.', numcount - 1) == NULL)))
		stro = ft_prependzero_zero(stro, str);
	if ((*str == '0') && ((ft_memchr(str, '-', numcount - 1))
			|| (ft_memchr(str, '.', numcount - 1))))
		stro = ft_prependspace_width(stro, str, count);
	if (*str == '#')
		stro = ft_hashtag(stro, str, str[numcount - 1]);
	if (ft_memchr(str, ' ', numcount - 1))
		stro = ft_prependspace_space(stro, str);
	if (ft_memchr(str, '+', numcount - 1))
		stro = ft_prependspace_space_plus(stro, str);
	if (ft_isdigit(str[0]) == 1 && str[0] != '0')
		stro = ft_prependspace_width(stro, str, count);
	return (stro);
}

char	*ft_firstargcheck(const char *str, va_list list, size_t *count)
{
	if (ft_strncmp(str, "c", 1) == 0)
		return (c_ft_chartostr(list, count, str));
	else if (ft_strncmp(str, "s", 1) == 0)
		return (s_ft_strtostr(list, str));
	else if (ft_strncmp(str, "p", 1) == 0)
		return (p_ft_ptrtostr(list));
	else if (ft_strncmp(str, "d", 1) == 0)
		return (d_ft_inttostr(list, str));
	else if (ft_strncmp(str, "i", 1) == 0)
		return (d_ft_inttostr(list, str));
	else if (ft_strncmp(str, "u", 1) == 0)
		return (u_ft_uninttostr(list));
	else if (ft_strncmp(str, "x", 1) == 0)
		return (ft_smallhextostr(list));
	else if (ft_strncmp(str, "X", 1) == 0)
		return (ft_bighextostr(list));
	else if (ft_strncmp(str, "%", 1) == 0 || ft_isformat(str) == '%')
		return (ft_perctostr());
	return (NULL);
}

static	void	ft_defaultcheck(const char *str, va_list list, size_t *count)
{
	size_t	i;
	size_t	strlen;
	char	*stro;

	i = 0;
	stro = ft_firstargcheck(&(str[i + 1]), list, count);
	if (stro == NULL)
		stro = ft_firstargcheck_bonus(&(str[i + 1]), list, count);
	ft_putstr_fd(stro, 1);
	strlen = ft_strlen(stro);
	(*count) += strlen;
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
/*
int	main(void)
{
	printf("\n%d\n", printf("{%3c}", 0));
	printf("\n%d", ft_printf("{%3c}", 0));
	return (0);
}
*/
