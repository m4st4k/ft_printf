/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:41:05 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/15 17:41:13 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int	ft_inttohexstr(size_t i, size_t iscap)
{
	char	*ptr;
	size_t	arrlen;
	size_t	val;

	if (!i)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	arrlen = 0;
	val = i;
	while (i)
	{
		i /= 16;
		arrlen++;
	}
	ptr = malloc(arrlen + 1);
	if (ptr == NULL)
		return (0);
	ptr[arrlen] = '\0';
	ft_printhex(val, ptr, arrlen, iscap);
	free(ptr);
	ptr = NULL;
	return (arrlen);
}
