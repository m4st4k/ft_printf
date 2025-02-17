/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:48:44 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/17 00:50:57 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*s1;

	s1 = (t_list *)malloc(sizeof(t_list));
	if (!s1)
		return (NULL);
	s1->content = content;
	s1->next = NULL;
	return (s1);
}
