/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:46:02 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/28 13:52:59 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
	{
		return (0);
	}
	while (n && (*s1 || *s2))
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		n--;
		s1++;
		s2++;
	}
	return (c1 - c2);
}
/*
int main(void)
{
	printf("%d\n", ft_strncmp("", "1", 42));
}
*/
