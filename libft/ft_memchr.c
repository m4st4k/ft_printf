/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:19:52 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/26 19:04:33 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	target;

	target = c;
	while (n)
	{
		if (*(unsigned char *)s == target)
		{
			return ((char *)s);
		}
		n--;
		s++;
	}
	return (NULL);
}
