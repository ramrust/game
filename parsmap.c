/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:30 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:33 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include "parsin.h"
#include <unistd.h>
#include <mlx.h>

void	parsNo(char **map, t_all *all, int i)
{
	if (all->NO.pt != NULL)
		errors2(12);
	all->NO.pt = &(map[i][3]);
	all->res.keys++;
}

void	parsWe(char **map, t_all *all, int i)
{
	if (all->WE.pt != NULL)
		errors2(12);
	all->WE.pt = &(map[i][3]);
	all->res.keys++;
}

void	parsEa(char **map, t_all *all, int i)
{	
	if (all->EA.pt != NULL)
		errors2(12);
	all->EA.pt = &(map[i][3]);
	all->res.keys++;
}

void	parsSo(char **map, t_all *all, int i)
{
	if (all->SO.pt != NULL)
		errors2(12);
	all->SO.pt = &(map[i][3]);
	all->res.keys++;
}

void	parsS(char **map, t_all *all, int i)
{
	if (all->S.s != NULL)
		errors2(12);
	all->S.s = &(map[i][2]);
	all->res.keys++;
}
