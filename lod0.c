/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lod0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:18:36 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:18:39 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"

void	initcub(t_all *all)
{	
	all->newc.psX = all->plr.x;
	all->newc.psY = all->plr.y;
	all->newc.drX = all->plr.dirX;
	all->newc.drY = all->plr.dirY;
	all->newc.plneX = all->plr.planeX;
	all->newc.plneY = all->plr.planeY;
	all->newc.numSprts = all->sprite.count;
}

void	initrays(t_all *all, int x)
{
	all->nr.camX = 2 * x / (double)all->res.x - 1;
	all->nr.rayDX = all->newc.drX + all->newc.plneX * all->nr.camX;
	all->nr.rayDY = all->newc.drY + all->newc.plneY * all->nr.camX;
	all->nr.mX = (int)all->newc.psX;
	all->nr.mY = (int)all->newc.psY;
	all->nr.deltaDX = fabs(1 / all->nr.rayDX);
	all->nr.deltaDY = fabs(1 / all->nr.rayDY);
	all->nr.hit = 0;
}

void	calcstep(t_all *all)
{
	if (all->nr.rayDX < 0)
	{
		all->nr.stpX = -1;
		all->nr.sideDX = (all->newc.psX - all->nr.mX) * all->nr.deltaDX;
	}
	else
	{
		all->nr.stpX = 1;
		all->nr.sideDX = (all->nr.mX + 1.0 - all->newc.psX) * all->nr.deltaDX;
	}
	if (all->nr.rayDY < 0)
	{
		all->nr.stpY = -1;
		all->nr.sideDY = (all->newc.psY - all->nr.mY) * all->nr.deltaDY;
	}
	else
	{
		all->nr.stpY = 1;
		all->nr.sideDY = (all->nr.mY + 1.0 - all->newc.psY) * all->nr.deltaDY;
	}
}

void	makestep(t_all *all)
{
	while (all->nr.hit == 0)
	{
		if (all->nr.sideDX < all->nr.sideDY)
		{
			all->nr.sideDX += all->nr.deltaDX;
			all->nr.mX += all->nr.stpX;
			all->nr.side = 0;
		}
		else
		{
			all->nr.sideDY += all->nr.deltaDY;
			all->nr.mY += all->nr.stpY;
			all->nr.side = 1;
		}
		if (all->only_m[all->nr.mY][all->nr.mX] =='1')
			all->nr.hit = 1;
	}
}

void	calcdnheight(t_all *all)
{
	if (all->nr.side == 0)
		all->nr.pWalDst = (all->nr.mX - all->newc.psX + (1 - all->nr.stpX)
				/ 2) / all->nr.rayDX;
	else
		all->nr.pWalDst = (all->nr.mY - all->newc.psY + (1 - all->nr.stpY)
				/ 2) / all->nr.rayDY;
	all->nr.lnHgt = (int)(all->res.y / all->nr.pWalDst);
	all->nr.drStrt = -all->nr.lnHgt / 2 + all->res.y / 2;
	if (all->nr.drStrt < 0)
		all->nr.drStrt = 0;
	all->nr.drEnd = all->nr.lnHgt / 2 + all->res.y / 2;
	if (all->nr.drEnd >= all->res.y)
		all->nr.drEnd = all->res.y;
}
