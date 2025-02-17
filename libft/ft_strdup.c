/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:37:49 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/03 13:48:10 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		length;
	size_t		i;

	if (!s && !*s)
		return (NULL);
	length = ft_strlen(s);
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
