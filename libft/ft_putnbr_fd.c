/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:17:26 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/13 12:30:11 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	char	*p;
	size_t	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	p = ft_itoa(n);
	if (!p)
		return ;
	i = 0;
	while (p[i] > 0)
	{
		str[i] = p[i];
		i++;
	}
	str[i] = '\0';
	free(p);
	ft_putstr_fd(str, fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 2);
}
*/
