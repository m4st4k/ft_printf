/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependspace_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:26:55 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/04 11:44:01 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static	char	*ft_paddspaces_minus(size_t width, char *str)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(str);
	if (width <= len)
		return (str);
	newstr = malloc((sizeof(char) * width) + 1);
	newstr[width] = '\0';
	while (width)
		newstr[--width] = ' ';
	while (len)
	{
		len--;
		newstr[len] = str[len];
	}
	free(str);
	return (newstr);
}

static	char	*ft_paddspaces_width(size_t width, char *str)
{
	size_t	strlen;
	size_t	i;
	char	*new;

	i = 0;
	strlen = ft_strlen(str);
	new = malloc((sizeof(char) * width) + 1);
	new[width] = '\0';
	while (width > strlen)
	{
		new[i++] = ' ';
		width--;
	}
	while (strlen)
	{
		new[i++] = *str++;
		strlen--;
	}
	free(str - width);
	return (new);
}

char	*ft_prependspace_width(char *stro, const char *str, size_t *count)
{
	int		width;
	size_t	strlen;
	size_t	numcount;
	char	*new;

	numcount = ft_formatspecsize(str);
	width = ft_atoi(str);
	if (width < 0)
		width = width * -1;
	strlen = ft_strlen(stro);
	if (strlen == 0 && str[numcount - 1] == 'c' && width != 0)
	{
		width--;
		(*count)++;
	}
	if ((size_t)width <= strlen)
		return (stro);
	new = ft_paddspaces_width(width, stro);
	return (new);
}

char	*ft_prependspace_space(char *stro, const char *str)
{
	size_t	strlen;
	size_t	width;
	size_t	numcount;
	char	*new;

	new = NULL;
	numcount = ft_formatspecsize(str);
	width = ft_formatspecsizebonus(str, ' ');
	strlen = ft_strlen(stro);
	if ((*stro != '-') && str[numcount - 1] != 's')
		new = ft_paddspaces_width(strlen + 1, stro);
	if (new != NULL)
		new = ft_prependspace_width(new, &(str[width]), 0);
	else
		new = ft_prependspace_width(stro, &(str[width]), 0);
	return (new);
}

char	*ft_prependspace_minus(char *stro, const char *str)
{
	int		width;
	size_t	numcount;
	size_t	start;

	start = ft_formatspecsizebonus(str, '-');
	width = ft_atoi(str + start);
	if (width < 0)
		width = width * -1;
	numcount = ft_formatspecsize(str);
	if ((str[numcount - 1] == 'c') && (*stro == 0))
		width--;
	stro = ft_paddspaces_minus(width, stro);
	return (stro);
}
