/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lod1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:18:45 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:18:48 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"

void	textone(t_all *all)
{
	if (all->nr.stpX > 0)
	{
		all->nr.texX = all->tex[3].tex_w - (int)(all->nr.wallX
				* all->tex[3].tex_w) - 1;
		all->nr.step = 1.0 * all->tex[3].tex_w / all->nr.lnHgt;
		all->nr.g = 3;
	}
	else
	{
		all->nr.texX = all->tex[2].tex_w - (int)(all->nr.wallX
				* all->tex[2].tex_w) - 1;
		all->nr.step = 1.0 * all->tex[2].tex_w / all->nr.lnHgt;
		all->nr.g = 2;
	}
}

void	textother(t_all *all)
{
	if (all->nr.stpY > 0)
	{
		all->nr.texX = all->tex[1].tex_w - (int)(all->nr.wallX
				* all->tex[1].tex_w) - 1;
		all->nr.step = 1.0 * all->tex[1].tex_w / all->nr.lnHgt;
		all->nr.g = 1;
	}
	else
	{
		all->nr.texX = all->tex[0].tex_w - (int)(all->nr.wallX
				* all->tex[0].tex_w) - 1;
		all->nr.step = 1.0 * all->tex[0].tex_w / all->nr.lnHgt;
		all->nr.g = 0;
	}
}

void	textonwall(t_all *all)
{
	if (all->nr.side == 0)
		all->nr.wallX = all->newc.psY + all->nr.pWalDst * all->nr.rayDY;
	else
		all->nr.wallX = all->newc.psX + all->nr.pWalDst * all->nr.rayDX;
	all->nr.wallX -= floor((all->nr.wallX));
	all->nr.g = 0;
	if (all->nr.side == 0)
		textone(all);
	else
		textother(all);
}

void	startsprt(t_all *all, int x)
{
	all->nr.texPos = (all->nr.drStrt - all->res.y / 2 + all->nr.lnHgt / 2)
		* all->nr.step;
	all->nr.y = all->nr.drStrt;
	while (all->nr.y < all->nr.drEnd)
	{
		all->nr.texY = (int)all->nr.texPos % (all->tex[all->nr.g].tex_h - 1);
		all->nr.texPos += all->nr.step;
		my_mlx_pixel_put(all, x, all->nr.y, get_color(all, all->nr.texX,
				all->nr.texY, all->nr.g));
		all->nr.y++;
	}
	all->newc.Zbuff[x] = all->nr.pWalDst;
}

void	sortsprite(t_all *all)
{
	int	i;
	int	t;
	int	temp;

	temp = all->newc.numSprts;
	i = -1;
	while (++i < all->newc.numSprts)
	{
		all->newc.spOr[i] = i;
		all->newc.sprtDist[i] = (pow(all->newc.psX - all->sprite.buf[i].x, 2)
				+ pow(all->newc.psY - all->sprite.buf[i].y, 2));
	}
	bubbleSort(all->newc.sprtDist, all->newc.spOr, all->newc.numSprts);
	i = -1;
	while (++i < ((temp - 1) / 2))
	{
		t = all->newc.sprtDist[temp - 1];
		all->newc.sprtDist[temp - 1] = all->newc.sprtDist[i];
		all->newc.sprtDist[i] = t;
		temp--;
	}
}
