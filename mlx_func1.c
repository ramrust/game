/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:48:12 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/25 00:48:16 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"
#include <unistd.h>

void	textinit0(t_all *all)
{
	all->tex[0].img = NULL;
	all->tex[0].addr = NULL;
	all->tex[1].img = NULL;
	all->tex[1].addr = NULL;
	all->tex[2].img = NULL;
	all->tex[2].addr = NULL;
}

void	textinit1(t_all *all)
{
	all->tex[4].img = NULL;
	all->tex[4].addr = NULL;
	all->tex[3].img = NULL;
	all->tex[3].addr = NULL;
}

void	checktext(t_all *all)
{
	if (mlx_xpm_file_to_image(all->win.mlx, all->NO.pt, &all->tex[0].tex_w,
			&all->tex[0].tex_h) == NULL)
		errors1(15);
	if (mlx_xpm_file_to_image(all->win.mlx, all->SO.pt, &all->tex[1].tex_w,
			&all->tex[1].tex_h) == NULL)
		errors1(15);
	if (mlx_xpm_file_to_image(all->win.mlx, all->WE.pt, &all->tex[2].tex_w,
			&all->tex[2].tex_h) == NULL)
		errors1(15);
	if (mlx_xpm_file_to_image(all->win.mlx, all->EA.pt, &all->tex[3].tex_w,
			&all->tex[3].tex_h) == NULL)
		errors1(15);
	if (mlx_xpm_file_to_image(all->win.mlx, all->S.s, &all->tex[4].tex_w,
			&all->tex[4].tex_h) == NULL)
		errors1(15);
}
