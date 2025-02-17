/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:37:29 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/28 16:00:39 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!n || ((dest == NULL) && (src == NULL)))
	{
		return ((char *)dest);
	}
	while (n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		n--;
		i++;
	}
	return ((char *)dest);
}
