/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:51:25 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/31 14:16:17 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclength;
	int		i;

	srclength = ft_strlen(src);
	i = 0;
	if (!size)
	{
		return (srclength);
	}
	while ((size > 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
