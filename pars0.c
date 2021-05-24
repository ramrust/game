/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:04 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:06 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

int	rgb_to_int_f(t_all *all)
{
	if (all->F.r > 255)
		errors(3);
	if (all->F.g > 255)
		errors(3);
	if (all->F.b > 255)
		errors(3);
	return ((int)all->F.r * 65536 + (int)all->F.g * 256 + (int)all->F.b);
}

void	checkcolorc(t_all *all)
{
	if (all->C.r != -1 || all->C.g != -1 || all->C.b != -1)
		errors(3);
}

void	checkcolorf(t_all *all)
{
	if (all->F.r != -1 || all->F.g != -1 || all->F.b != -1)
		errors(3);
}

void	checkcolorca(t_all *all)
{
	if (all->C.r == -1 || all->C.g == -1 || all->C.b == -1)
		errors(3);
}

void	checkcolorfa(t_all *all)
{
	if (all->F.r == -1 || all->F.g == -1 || all->F.b == -1)
		errors(3);
}
