/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:31 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/11 03:28:05 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static	void	ft_ptrtostr(size_t i, size_t arrlen)
{
	char	*ptr;

	ptr = malloc(arrlen + 1);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr[arrlen] = '\0';
	ft_printhex(i, ptr, arrlen, 0);
	free(ptr);
	ptr = NULL;
}

int	ft_printptr(void *addr)
{
	size_t	i;
	size_t	arrlen;
	size_t	strlen;

	if (addr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = (size_t)(addr);
	arrlen = 0;
	while (i)
	{
		i /= 16;
		arrlen++;
	}
	arrlen += 2;
	strlen = arrlen;
	i = (size_t)addr;
	ft_ptrtostr(i, arrlen);
	return (strlen);
}
