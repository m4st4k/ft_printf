/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perctostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:38 by dbriant           #+#    #+#             */
/*   Updated: 2025/03/27 02:51:14 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_perctostr(void)
{
	char	*str;

	str = malloc((sizeof(char) * 1) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
