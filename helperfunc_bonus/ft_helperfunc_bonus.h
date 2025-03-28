/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helperfunc_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:46:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 12:07:38 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "../libft/libft.h"
#include "../ft_printf.h"

char	*ft_prependzero(va_list list, const char *str, size_t *count);
