/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ft_ptrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:01:05 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:57:24 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*ft_addprefix(char *dest, size_t len)
{
	dest = malloc(((sizeof(char) * len) + 2) + 1);
	if (dest == NULL)
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	dest[len + 2] = '\0';
	return (dest);
}

static	char	*ft_setnil(void)
{
	char	*str;

	str = malloc((sizeof(char) * 5) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'i';
	str[3] = 'l';
	str[4] = ')';
	str[5] = '\0';
	return (str);
}

char	*p_ft_ptrtostr(va_list list)
{
	char	*dest;
	char	*org;
	size_t	len;
	size_t	val;

	val = (size_t)va_arg(list, void *);
	if (val == 0)
		return (ft_setnil());
	dest = NULL;
	org = ft_sizettohex(val);
	len = ft_strlen(org);
	dest = ft_addprefix(dest, len);
	if (org == NULL || dest == NULL)
		return (NULL);
	while (len)
	{
		len--;
		dest[len + 2] = ft_tolower(org[len]);
	}
	free(org);
	org = NULL;
	return (dest);
}
