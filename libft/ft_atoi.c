/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:01:09 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/03 09:59:16 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_isnegative(const char *neg)
{
	if (*neg == '-')
		return (1);
	else if (*neg == '+')
		return (2);
	else if (ft_isdigit(*neg) == 1)
		return (3);
	return (0);
}

static	char	*ft_ignoreprint(const char *neg)
{
	char	i;

	i = '\t';
	while (i <= '\r')
	{
		while (*neg == i || *neg == ' ')
		{
			neg++;
			i = '\t';
		}
		i++;
	}
	while (((*neg == '-') || (*neg == '+')) && !ft_isdigit(*(neg + 1)))
		neg++;
	return ((char *)neg);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		isneg;
	int		num;

	num = 0;
	i = 0;
	nptr = ft_ignoreprint(nptr);
	isneg = ft_isnegative(nptr);
	if (!isneg || *nptr == '\0')
		return (0);
	else if (isneg != 3)
		nptr++;
	while (ft_isdigit(nptr[i]))
		num = (nptr[i++] - '0') + (num * 10);
	if (isneg == 1)
		num = -num;
	return (num);
}
/*
int	main(void)
{
	char num[] = "\212 139";
	printf("Return: %d\n", ft_atoi(num));
	printf("Return: %d\n", atoi(num));
}
*/
