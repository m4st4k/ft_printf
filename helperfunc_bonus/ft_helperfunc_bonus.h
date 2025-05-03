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
#include "../ft_printf.h"

char	*ft_prependzero_zero(char *stro, const char *str);
char	*ft_prependzero_dot(char *stro, const char *str);
char	*ft_prependspace_minus(char *stro, const char *str);
char	*ft_prependspace_width(char *stro, const char *str, size_t *count);
char	*ft_prependspace_space(char *stro, const char *str);
char	*ft_prependspace_space_plus(char *stro, const char *str);
size_t	ft_formatspecsizebonus(const char *str, char i);
char	*ft_hashtag(char *str, const char *stro, char c);
char	*ft_space(char *str, const char *stra);
char	*rightalignment(char *str);
