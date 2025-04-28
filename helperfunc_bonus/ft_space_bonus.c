/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:19:48 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/07 18:04:36 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "ft_helperfunc_bonus.h"
#include "../libft/libft.h"
#include <stdlib.h>

static	char	*ft_prependonespace(char *stro, size_t len)
{
	stro = malloc(((sizeof(char) * len) + 1) + 1);
	if (stro == NULL)
		return (NULL);
	stro[0] = ' ';
	return (stro);
}

char	*ft_space(char *str, const char *stra)
{
	size_t	len;
	size_t	i;
	size_t	numcount;
	char	*stro;

	stro = NULL;
	numcount = ft_formatspecsize(stra);
	//return (str);
	if (ft_isdigit(stra[1]) && (stra[numcount - 1] == 's'))
	{
		stro = ft_prependspace(str, &(stra[1]));
		return (stro);
		//printf("String: %st\n", stro);
		stro = rightalignment(stro);
		len = ft_strlen(stro);
		stro[len] = '\0';
		//printf("String: %st\n", stro);
		//return (stro);
	}
	i = 0;
	len = ft_strlen(str);
	stro = ft_prependonespace(stro, len);
	if (stro == NULL)
		return (NULL);
	while (i < len)
	{
		stro[i + 1] = str[i];
		i++;
	}
	free(str);
	return (stro);
}
