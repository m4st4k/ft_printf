/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:34:12 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/28 16:47:18 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (!n || ((s1 == NULL) && (s2 == NULL)))
	{
		return (0);
	}
	while (n)
	{
		c1 = *(unsigned char *)s1;
		c2 = *(unsigned char *)s2;
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		s1++;
		s2++;
		n--;
	}
	return (c1 - c2);
}
