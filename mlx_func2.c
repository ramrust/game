/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:19:35 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:19:36 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parsin.h"
#include "libft/libft.h"
#include <unistd.h>

void	bubbleSort(double *num, double *s, int size)
{
	int	i;
	int	j;
	int	t;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = (size - 1);
		while (j > i)
		{
			if (num[j] > num[j - 1])
			{
				temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
				t = s[j - 1];
				s[j - 1] = s[j];
				s[j] = t;
			}
			j--;
		}
		i++;
	}
}

int	ft_close(t_all *all, int win)
{
	if (win == 1)
		mlx_destroy_window(all->win.mlx, all->win.win);
	exit(0);
	return (1);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	dst = all->img.addr + (y * all->img.line_length + x
			* (all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_all *all, int x, int y, int i)
{
	char			*dst;
	unsigned int	color;

	dst = all->tex[i].addr + (y * all->tex[i].line_length + x
			* (all->tex[i].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	ft_clean_window(t_all *all, int f, int c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->res.y / 2)
	{
		j = -1;
		while (++j < all->res.x)
			my_mlx_pixel_put(all, j, i, f);
	}
	while (++i < all->res.y)
	{
		j = -1;
		while (++j < all->res.x)
			my_mlx_pixel_put(all, j, i, c);
	}
}
