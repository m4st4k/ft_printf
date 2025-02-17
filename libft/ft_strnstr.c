/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:09:04 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/31 17:56:35 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	sizelittle;

	sizelittle = ft_strlen(little);
	if (sizelittle == 0)
	{
		return ((char *)big);
	}
	while (*big && len >= sizelittle)
	{
		if (ft_memcmp(big, little, sizelittle) == 0)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
