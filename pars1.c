/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:04 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:06 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

void	keysinit(t_all *all)
{
	all->NO.pt = NULL;
	all->WE.pt = NULL;
	all->EA.pt = NULL;
	all->SO.pt = NULL;
	all->S.s = NULL;
	all->res.x = 0;
	all->res.y = 0;
	all->C.r = -1;
	all->C.g = -1;
	all->C.b = -1;
	all->F.r = -1;
	all->F.g = -1;
	all->F.b = -1;
}

int	skip_space(char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	return (i);
}
