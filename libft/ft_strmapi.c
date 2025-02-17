/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:43:35 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/13 07:18:07 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	i = 0;
	str = ft_strdup(s);
	if (!str)
		return (str);
	while (i < len)
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (str);
}
