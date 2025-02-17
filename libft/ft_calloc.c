/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:03:47 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/03 11:33:21 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	length;
	void	*str;

	length = nmemb * size;
	str = malloc(nmemb * size);
	if (str == NULL)
	{
		return (NULL);
	}
	else if (!nmemb || !size)
	{
		return (str);
	}
	while (length)
	{
		((char *)str)[length - 1] = '\0';
		length--;
	}
	return (str);
}
