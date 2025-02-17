/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:38:07 by dbriant           #+#    #+#             */
/*   Updated: 2024/12/24 13:01:32 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for alphabetic characters
// 1. check if is upper.
// 2. check if is lower.

static	int	ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

static	int	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
	{
		return (1);
	}
	return (0);
}
