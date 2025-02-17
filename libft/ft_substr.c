/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:56:42 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/05 19:12:55 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	strlen = ft_strlen(s);
	if (start >= strlen || len == 0)
		return (ft_strdup(""));
	if (start + len > strlen)
		len = strlen - start;
	if (!start && len > strlen)
		substr = malloc(strlen + 1);
	else
		substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
