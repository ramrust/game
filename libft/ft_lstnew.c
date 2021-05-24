/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:35:24 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/21 21:35:28 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem1;

	elem1 = malloc(sizeof(t_list));
	if (elem1)
	{
		elem1->content = content;
		elem1->next = (NULL);
	}
	return (elem1);
}
