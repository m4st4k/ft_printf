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
#include <stddef.h>
#include <stdarg.h>

extern	int	ft_printf(const char *str, ...);
extern	int	ft_firstargcheck(const char *str, va_list list, size_t *count);
extern	int ft_bonusargcheck(const char *str, va_list list, size_t *count);
extern	int	ft_printptr(void *addr);
extern	int	ft_inttohexstr(size_t i, size_t iscap);
extern	void	ft_printhex(size_t i, char *ptr, size_t arrlen, size_t iscap);
extern	int	ft_printint(int val);
extern	int	ft_printunint(unsigned int val);
extern	int	ft_printstr(char *str);