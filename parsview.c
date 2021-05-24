/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:39 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:41 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

void	we_pos(t_all *all)
{
	all->plr.dirX = -1.0;
	all->plr.dirY = 0.0;
	all->plr.planeX = 0.0;
	all->plr.planeY = -0.70;
	all->only_m[(int)all->plr.y][(int)all->plr.x] = '0';
}

void	ea_pos(t_all *all)
{
	all->plr.dirX = 1.0;
	all->plr.dirY = 0.0;
	all->plr.planeX = 0.0;
	all->plr.planeY = 0.70;
	all->only_m[(int)all->plr.y][(int)all->plr.x] = '0';
}

void	so_pos(t_all *all)
{
	all->plr.dirX = 0.0;
	all->plr.dirY = 1.0;
	all->plr.planeX = -0.70;
	all->plr.planeY = 0.0;
	all->only_m[(int)all->plr.y][(int)all->plr.x] = '0';
}

void	no_pos(t_all *all)
{
	all->plr.dirX = 0.0;
	all->plr.dirY = -1.0;
	all->plr.planeX = 0.70;
	all->plr.planeY = 0.0;
	all->only_m[(int)all->plr.y][(int)all->plr.x] = '0';
}

void	check_view(t_all *all, int i, int j)
{	
	all->plr.x = j + 0.5;
	all->plr.y = i + 0.5;
	if (all->only_m[i][j] == 'E')
	{
		ea_pos(all);
		all->plr.fl++;
	}
	else if (all->only_m[i][j] == 'W')
	{
		we_pos(all);
		all->plr.fl++;
	}
	else if (all->only_m[i][j] == 'S')
	{
		so_pos(all);
		all->plr.fl++;
	}
	else if (all->only_m[i][j] == 'N')
	{
		no_pos(all);
		all->plr.fl++;
	}
	if (all->plr.fl > 1 || all->plr.fl == 0)
		errors1(8);
}
