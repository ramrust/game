/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 09:57:35 by rulrike           #+#    #+#             */
/*   Updated: 2020/11/07 11:53:58 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)buf;
	while (len > i)
	{
		temp[i] = ch;
		i++;
	}
	return (buf);
}
