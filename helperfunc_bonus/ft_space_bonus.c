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

char	*ft_prependspace_space_plus(char *stro, const char *str)
{
	size_t	width;
	size_t	count;
	char	*new;

	new = NULL;
	width = ft_formatspecsizebonus(str, '+');
	if (!width)
		return (stro);
	count = ft_atoi(&(str[width]));
	if (!count)
		return (stro);
	new = ft_prependspace_width(stro, &(str[width]), 0);
	return (new);
}
