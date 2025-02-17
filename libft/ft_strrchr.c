/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:14:57 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/25 21:16:02 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[size]);
	}
	while (size > 0)
	{
		if ((unsigned char)s[size - 1] == (unsigned char)c)
		{
			return ((char *)&s[size - 1]);
		}
		size--;
	}
	return (NULL);
}
