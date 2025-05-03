/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:27:01 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/11 03:02:31 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include "helperfunc_bonus/ft_helperfunc_bonus.h"
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_firstargcheck(const char *str, va_list list, size_t *count);
char	*ft_firstargcheck_bonus(const char *str, va_list list, size_t *count);
size_t	ft_checkifnum(const char *str);
char	*c_ft_chartostr(va_list list, size_t *count, const char *str);
char	*s_ft_strtostr(va_list list, const char *str);
char	*p_ft_ptrtostr(va_list list);
char	*ft_sizettohex(size_t val);
char	*d_ft_inttostr(va_list list, const char *str);
char	*u_ft_uninttostr(va_list list);
char	*ft_smallhextostr(va_list list);
char	*ft_bighextostr(va_list list);
char	*ft_perctostr(void);
size_t	ft_formatspecsize(const char *str);
char	ft_isformat(const char *str);

#endif