/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ft_strtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:59:09 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/25 04:31:20 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	const char	*ft_returnpercent(const char *str)
{
	while (*str != '%')
		str--;
	return (++str);
}

static	void	ft_precisiononnull(const char *str, char *stro)
{
	size_t	start;
	size_t	numcount;
	int		width;

	str = ft_returnpercent(str);
	numcount = ft_formatspecsize(str);
	start = ft_formatspecsizebonus(str, '.');
	width = ft_atoi(str + start);
	if ((str[numcount - 1] == 's' || str[numcount - 1] == 'p')
		&& (!ft_strncmp(stro, "(null)", 6))
		&& start != 0)
	{
		if (width < 6)
			stro[0] = '\0';
	}
}

char	*s_ft_strtostr(va_list list, const char *strs)
{
	char	*str;
	char	*strorg;
	size_t	len;

	len = 0;
	strorg = (char *)va_arg(list, char *);
	if (strorg == NULL)
	{
		str = malloc((sizeof(char) * 6) + 1);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		str[6] = '\0';
		ft_precisiononnull(strs, str);
		return (str);
	}
	len = ft_strlen(strorg);
	str = malloc((sizeof(char) * len) + 1);
	str = ft_memcpy(str, strorg, len);
	str[len] = '\0';
	return (str);
}
