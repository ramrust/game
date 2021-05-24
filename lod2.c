/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lod2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:18:52 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:18:56 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"

void	spriteinit(t_all *all, int i)
{
	all->sps.spX = all->sprite.buf[(int)all->newc.spOr[i]].x - all->newc.psX;
	all->sps.spY = all->sprite.buf[(int)all->newc.spOr[i]].y - all->newc.psY;
	all->sps.inD = 1.0 / (all->newc.plneX * all->newc.drY - all->newc.drX
			* all->newc.plneY);
	all->sps.tfX = all->sps.inD * (all->newc.drY * all->sps.spX - all->newc.drX
			* all->sps.spY);
	all->sps.tfY = all->sps.inD * (-all->newc.plneY * all->sps.spX
			+ all->newc.plneX * all->sps.spY);
	all->sps.ssx = (int)((all->res.x / 2) * (1 + all->sps.tfX / all->sps.tfY));
	all->sps.vms = (int)(0.0 / all->sps.tfY);
	all->sps.sH = abs((int)(all->res.y / (all->sps.tfY))) / 1;
	all->sps.dsY = -all->sps.sH / 2 + all->res.y / 2 + all->sps.vms;
	if (all->sps.dsY < 0)
		all->sps.dsY = 0;
	all->sps.deY = all->sps.sH / 2 + all->res.y / 2 + all->sps.vms;
	if (all->sps.deY >= all->res.y)
		all->sps.deY = all->res.y;
	all->sps.spW = abs((int)(all->res.y / (all->sps.tfY))) / 1;
	all->sps.dsX = -all->sps.spW / 2 + all->sps.ssx;
	if (all->sps.dsX < 0)
		all->sps.dsX = 0;
	all->sps.deX = all->sps.spW / 2 + all->sps.ssx;
	if (all->sps.deX >= all->res.x)
		all->sps.deX = all->res.x;
}

void	drawhelper(t_all *all, int d)
{
	int	stripe;

	stripe = all->sps.dsX;
	while (stripe < all->sps.deX)
	{
		all->nr.texX = (int)(256 * (stripe - (-all->sps.spW / 2 + all->sps.ssx))
				* all->tex[4].tex_w / all->sps.spW) / 256;
		if (all->sps.tfY > 0 && stripe > 0 && stripe < all->res.x
			&& all->sps.tfY < all->newc.Zbuff[stripe])
		{
			all->nr.y = all->sps.dsY;
			while (all->nr.y < all->sps.deY)
			{
				d = (all->nr.y - all->sps.vms) * 256 - all->res.y * 128
					+ all->sps.sH * 128;
				all->nr.texY = ((d * all->tex[4].tex_h) / all->sps.sH) / 256;
				if ((get_color(all, all->nr.texX, all->nr.texY, 4)
						& 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all, stripe, all->nr.y,
						get_color(all, all->nr.texX, all->nr.texY, 4));
				all->nr.y++;
			}
		}
		stripe++;
	}
}

void	drawspritenwall(t_all *all)
{
	int	i;
	int	d;

	d = 0;
	i = -1;
	while (++i < all->newc.numSprts)
	{
		spriteinit(all, i);
		drawhelper(all, d);
	}
}

int	screenmake(t_all *all)
{
	if (all->save)
	{
		create_bmp(all);
		key_press(53, all);
	}
	else if (all->save > 1)
		errors2(10);
	else if (all->save == 0)
		return (0);
	return (1);
}

int	newcub(t_all *all, int f, int c, int x)
{
	initcub(all);
	all->img.img = mlx_new_image(all->win.mlx, all->res.x, all->res.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
	f = rgb_to_int_f(all);
	c = rgb_to_int_c(all);
	ft_clean_window(all, c, f);
	x = -1;
	while (++x < all->res.x)
	{
		initrays(all, x);
		calcstep(all);
		makestep(all);
		calcdnheight(all);
		textonwall(all);
		startsprt(all, x);
	}
	sortsprite(all);
	drawspritenwall(all);
	screenmake(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.img, 0, 0);
	mlx_destroy_image(all->win.mlx, all->img.img);
	return (1);
}
