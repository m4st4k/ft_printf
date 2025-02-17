/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:10:47 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/27 21:00:51 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	int	substrcounter(const char *s, char c, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		while (s[i] == c && i < len)
			i++;
		if (s[i] != c && i < len)
		{
			count++;
			while (s[i] != c && i < len)
				i++;
		}
	}
	return (count);
}

static	char	**storeinarr(const char *s, char c, char **result, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = -1;
	j = 0;
	start = 0;
	while (++i, i <= len)
	{
		if (s[i] == c || !s[i])
		{
			if (i > start)
			{
				result[j] = ft_substr(s, start, i - start);
				if (!result[j])
					return (NULL);
				j++;
			}
			start = i + 1;
		}
	}
	result[j] = NULL;
	return ((char **)result);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	size_t	substrcount;
	char	**result;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	substrcount = substrcounter(s, c, len);
	result = (char **)malloc((substrcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (storeinarr(s, c, result, len));
}
