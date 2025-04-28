/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:36:24 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/04 13:03:46 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdlib.h>

static	char	*ft_addprefix(char *dest, size_t len, char c)
{
	dest = malloc(((sizeof(char) * len) + 2) + 1);
	if (dest == NULL)
		return (NULL);
	dest[0] = '0';
	dest[1] = c;
	dest[len + 2] = '\0';
	return (dest);
}

char	*ft_hashtag(char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*stro;

	if (*str == '0')
		return (str);
	i = 0;
	len = ft_strlen(str);
	stro = ft_addprefix(str, len, c);
	if (stro == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		stro[i + 2] = str[i];
		i++;
	}
	free(str);
	return (stro);
}
