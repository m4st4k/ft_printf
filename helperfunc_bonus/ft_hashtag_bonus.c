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
#include "../ft_printf.h"

static	char	*ft_addprefix(char *str, size_t len, char c)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(((sizeof(char) * len) + 2) + 1);
	if (new == NULL)
		return (NULL);
	new[len + 2] = '\0';
	new[0] = '0';
	new[1] = c;
	while (str[i] != '\0')
	{
		new[i + 2] = str[i];
		i++;
	}
	free(str);
	return (new);
}

char	*ft_hashtag(char *str, const char *stro, char c)
{
	size_t	len;
	size_t	width;
	size_t	count;
	char	*new;

	new = NULL;
	len = ft_strlen(str);
	width = ft_formatspecsizebonus(str, '#');
	count = ft_atoi(&(stro[width + 1]));
	if (*str == '0' && count == 0)
		return (str);
	if (*str != '0')
		new = ft_addprefix(str, len, c);
	if (count != 0 && new != NULL)
		new = ft_prependspace_width(new, &(stro[width + 1]), 0);
	else if (count != 0 && new == NULL)
		new = ft_prependspace_width(str, &(stro[width + 1]), 0);
	return (new);
}
