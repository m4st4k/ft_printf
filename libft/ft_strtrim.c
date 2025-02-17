/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:52:12 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/08 19:13:12 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static	char	*failcheck(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

static	char	*firstwhile(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

static	char	*secondwhile(size_t i, size_t end, char *ptr, const char *s1)
{
	size_t	s;

	s = -1;
	i = i - 1;
	while (++i, ++s, i <= end)
		ptr[s] = s1[i];
	ptr[s] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lens1;
	size_t	end;
	size_t	i;
	char	*ptr;

	lens1 = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set || !lens1)
		return (failcheck());
	i = 0;
	end = lens1 - 1;
	while (i <= end && ft_strchr(set, s1[i]))
		i++;
	while (end > i && ft_strchr(set, s1[end]))
		end--;
	if (i > end)
		return (firstwhile());
	ptr = malloc((end - i) + 2);
	if (!ptr)
		return (NULL);
	return (secondwhile(i, end, ptr, s1));
}
/*
int	main(void)
{
	printf("Return: %s", 
	ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "));
	return (0);
}
*/
