/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:20:37 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/31 17:58:15 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (size <= dstlen)
	{
		return (size + srclen);
	}
	while (*src && (dstlen + 1 < size))
	{
		dst[dstlen] = *src;
		dstlen++;
		src++;
	}
	dst[dstlen] = '\0';
	return (i + srclen);
}
