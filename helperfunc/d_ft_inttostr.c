/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ft_inttostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:03:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 00:14:51 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdarg.h>

char	*d_ft_inttostr(va_list list)
{
	char	*i;

	i = ft_itoa(va_arg(list, int));
	return (i);
}
