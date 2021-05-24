/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func3moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:19:51 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:19:53 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"
#include <unistd.h>

void	move_forward(t_all *all)
{
	if (all->only_m[(int)(all->plr.y + all->plr.dirY)]
			[(int)(all->plr.x + all->plr.dirX)] == '0')
	{
		all->plr.x += all->plr.dirX * 0.5;
		all->plr.y += all->plr.dirY * 0.5;
	}
}

void	move_right(t_all *all)
{
	if (all->only_m[(int)(all->plr.y + all->plr.planeY)]
			[(int)(all->plr.x + all->plr.planeX)] == '0')
	{
		all->plr.x += all->plr.planeX * 0.5;
		all->plr.y += all->plr.planeY * 0.5;
	}
}

void	move_left(t_all *all)
{
	if (all->only_m[(int)(all->plr.y - all->plr.planeY)]
			[(int)(all->plr.x - all->plr.planeX)] == '0')
	{
		all->plr.x -= all->plr.planeX * 0.5;
		all->plr.y -= all->plr.planeY * 0.5;
	}
}

void	move_back(t_all *all)
{
	if (all->only_m[(int)(all->plr.y - all->plr.dirY)]
			[(int)(all->plr.x - all->plr.dirX)] == '0')
	{
		all->plr.x -= all->plr.dirX * 0.5;
		all->plr.y -= all->plr.dirY * 0.5;
	}
}

void	rotate_l(t_all *all)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rtSpd;

	rtSpd = 0.05;
	oldDirX = all->plr.dirX;
	all->plr.dirX = all->plr.dirX * cos(-rtSpd) - all->plr.dirY * sin(-rtSpd);
	all->plr.dirY = oldDirX * sin(-rtSpd) + all->plr.dirY * cos(-rtSpd);
	oldPlaneX = all->plr.planeX;
	all->plr.planeX = all->plr.planeX
		 * cos(-rtSpd) - all->plr.planeY * sin(-rtSpd);
	all->plr.planeY = oldPlaneX * sin(-rtSpd) + all->plr.planeY * cos(-rtSpd);
}
