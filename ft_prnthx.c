/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnthx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:52:59 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/11 03:01:32 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_printhex(size_t i, char *ptr, size_t arrlen, size_t iscap)
{
	if (!i)
		ptr[--arrlen] = (i % 16) + '0';
	else
	{
		while (i)
		{
			ptr[--arrlen] = (i % 16) + '0';
			if (ptr[arrlen] > '9')
			{
				if (iscap)
					ptr[arrlen] += 7;
				else
					ptr[arrlen] += 39;
			}
			i /= 16;
		}
		ft_putstr_fd(ptr, 1);
	}
}
