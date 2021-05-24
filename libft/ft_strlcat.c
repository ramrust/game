/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:23:27 by rulrike           #+#    #+#             */
/*   Updated: 2020/11/24 16:15:42 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	sr;
	size_t	i;

	if (!dst && !src)
		return (0);
	ds = ft_strlen(dst);
	sr = ft_strlen(src);
	dst += ds;
	i = sr;
	if (!dstsize || ds >= dstsize)
		return (dstsize + sr);
	while ((sr > 0) && ((dstsize - ds - 1) > 0) && *src)
	{
		*dst++ = *src++;
		sr--;
		dstsize--;
	}
	*dst = '\0';
	return (ds + i);
}
