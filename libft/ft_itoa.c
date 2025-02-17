/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:59:53 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/13 12:06:08 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

//allocates the size for the given int

static	char	*allocsize(int n, size_t isneg)
{
	size_t	index;
	char	*str;
	void	*ptr;

	if (!n)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		((char *)str)[0] = '0';
		((char *)str)[1] = '\0';
		return ((char *)str);
	}
	index = 0;
	while (n > 0)
	{
		n = n / 10;
		index++;
	}
	if (isneg)
		index++;
	ptr = (char *)malloc((sizeof(char) * index) + 1);
	if (!ptr)
		return (NULL);
	return ((char *)ptr);
}
//converts the int to individual chars, stores as element  in array

static	int	ft_modulcalc(char *str, int n)
{
	int	index;

	index = 0;
	while (n)
	{
		str[index] = (n % 10) + '0';
		n = n / 10;
		index++;
	}
	str[index] = '\0';
	return (index);
}
//reverse the order of the content within the table

static	char	*ft_fliptable(char *flip, char *str, int i, int index)
{
	while (index)
	{
		flip[i] = str[index - 1];
		i++;
		index--;
	}
	flip[i] = '\0';
	free(str);
	return (flip);
}
//main itoa function

static	int	negtopos(int n, size_t *ptrisneg)
{
	if (n < 0 && n > -2147483648)
	{
		*ptrisneg = 1;
		return (-n);
	}
	else if (n < -2147483647)
	{
		*ptrisneg = 2;
		return (-n - 1);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	**str;
	size_t	*ptrisneg;
	size_t	isneg;
	int		index;
	int		i;

	isneg = 0;
	ptrisneg = &isneg;
	n = negtopos(n, ptrisneg);
	if (!n)
		return (allocsize(n, isneg));
	str = malloc(2 * sizeof(char *));
	if (!str)
		return (NULL);
	str[0] = allocsize(n, isneg);
	str[1] = allocsize(n, isneg);
	index = ft_modulcalc(str[0], n);
	i = 0;
	if (isneg)
		str[1][i++] = '-';
	if (isneg == 2)
		str[0][0] = str[0][0] + 1;
	ptrisneg = (void *)ft_fliptable(str[1], str[0], i, index);
	free(str);
	return ((char *)ptrisneg);
}
/*
int	main(void)
{
	printf("Return: %s", ft_itoa(-2147483648));
}
*/
