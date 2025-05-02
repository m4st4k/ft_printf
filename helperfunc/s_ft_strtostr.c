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

char	*s_ft_strtostr(va_list list)
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
		return (str);
	}
	len = ft_strlen(strorg);
	str = malloc(len + 1);
	str = ft_memcpy(str, strorg, len);
	str[len] = '\0';
	return (str);
}
