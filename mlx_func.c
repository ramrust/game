/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:19:26 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:19:29 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"
#include <unistd.h>

void	get_data_tex(t_all *all)
{	
	checktext(all);
	all->tex[0].img = mlx_xpm_file_to_image(all->win.mlx, all->NO.pt,
			&all->tex[0].tex_w, &all->tex[0].tex_h);
	all->tex[0].addr = mlx_get_data_addr(all->tex[0].img,
			&all->tex[0].bits_per_pixel, &all->tex[0].line_length,
			&all->tex[0].endian);
	if (all->tex[0].img == NULL || all->tex[0].addr == NULL)
		errors1(15);
	all->tex[1].img = mlx_xpm_file_to_image(all->win.mlx, all->SO.pt,
			&all->tex[1].tex_w, &all->tex[1].tex_h);
	all->tex[1].addr = mlx_get_data_addr(all->tex[1].img,
			&all->tex[1].bits_per_pixel,
			&all->tex[1].line_length, &all->tex[1].endian);
	if (!(all->tex[1].img) || !(all->tex[1].addr))
		errors1(15);
	all->tex[2].img = mlx_xpm_file_to_image(all->win.mlx, all->WE.pt,
			&all->tex[2].tex_w, &all->tex[2].tex_h);
	all->tex[2].addr = mlx_get_data_addr(all->tex[2].img,
			&all->tex[2].bits_per_pixel,
			&all->tex[2].line_length, &all->tex[2].endian);
	if (all->tex[2].img == NULL || all->tex[2].addr == NULL)
		errors1(15);
}

void	get_data_text(t_all *all)
{
	all->tex[3].img = mlx_xpm_file_to_image(all->win.mlx, all->EA.pt,
			&all->tex[3].tex_w, &all->tex[3].tex_h);
	all->tex[3].addr = mlx_get_data_addr(all->tex[3].img,
			&all->tex[3].bits_per_pixel,
			&all->tex[3].line_length, &all->tex[3].endian);
	if (all->tex[3].img == NULL || all->tex[3].addr == NULL)
		errors1(15);
	all->tex[4].img = mlx_xpm_file_to_image(all->win.mlx, all->S.s,
			&all->tex[4].tex_w, &all->tex[4].tex_h);
	all->tex[4].addr = mlx_get_data_addr(all->tex[4].img,
			&all->tex[4].bits_per_pixel,
			&all->tex[4].line_length, &all->tex[4].endian);
	if (all->tex[4].img == NULL || all->tex[4].addr == NULL)
		errors1(15);
}

void	rotate_r(t_all *all)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rtSpd;

	rtSpd = 0.05;
	oldDirX = all->plr.dirX;
	all->plr.dirX = all->plr.dirX * cos(rtSpd) - all->plr.dirY * sin(rtSpd);
	all->plr.dirY = oldDirX * sin(rtSpd) + all->plr.dirY * cos(rtSpd);
	oldPlaneX = all->plr.planeX;
	all->plr.planeX = all->plr.planeX * cos(rtSpd)
		- all->plr.planeY * sin(rtSpd);
	all->plr.planeY = oldPlaneX * sin(rtSpd) + all->plr.planeY * cos(rtSpd);
}

int	key_press(int key, t_all *all)
{
	if (key == 13)
		move_forward(all);
	if (key == 1)
		move_back(all);
	if (key == 2)
		move_right(all);
	if (key == 0)
		move_left(all);
	if (key == 123)
		rotate_l(all);
	if (key == 124)
		rotate_r(all);
	if (key == 53)
		exit(0);
	return (0);
}

void	print_map(t_all *all)
{
	int	f;
	int	c;

	f = 0;
	c = 0;
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->res.x,
			all->res.y, "Cub3D");
	all->img.img = mlx_new_image(all->win.mlx, all->res.x, all->res.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
	get_data_tex(all);
	get_data_text(all);
	newcub(all, f, c, 0);
	mlx_hook(all->win.win, 2, 0, key_press, all);
	mlx_hook(all->win.win, 17, 0, ft_close, all);
	mlx_loop_hook(all->win.mlx, (newcub), all);
	mlx_loop(all->win.mlx);
}
