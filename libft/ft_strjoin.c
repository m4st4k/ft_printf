/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:34:54 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/05 23:17:38 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	if (!s1 || !s2)
		ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	else if (!*s1 && !s2)
		ptr = (char *)malloc(ft_strlen(s1) + 1);
	else if (!s1 && !*s2)
		ptr = (char *)malloc(ft_strlen(s2) + 1);
	else if (!*s1 && !*s2)
		ptr = (char *)malloc(1);
	else if (ft_strlen(s1) < ft_strlen(s2) || ft_strlen(s1) > ft_strlen(s2)
		|| ft_strlen(s1) == ft_strlen(s2))
		ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i, i < ft_strlen(s1))
		ptr[i] = s1[i];
	i = -1;
	while (++i, i < ft_strlen(s2))
		ptr[ft_strlen(s1) + i] = s2[i];
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	printf("Return: %s", ft_strjoin("This", "Name"));
}
*/
