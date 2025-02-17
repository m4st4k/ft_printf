/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvIin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:52:08 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/31 14:15:37 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*sr;

	des = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (!n || (!des && !sr))
		return (dest);
	if (des < sr || des >= (sr + n))
	{
		while (n--)
		{
			*des++ = *sr++;
		}
	}
	else
	{
		des = des + n;
		sr = sr + n;
		while (n--)
		{
			*(--des) = *(--sr);
		}
	}
	return (dest);
}
