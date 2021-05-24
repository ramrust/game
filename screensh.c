/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screensh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:51 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:53 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsin.h"

static void	add_to_bit(char *t, int i, int k)
{
	t[i] = k % 256;
	t[i + 1] = k / 256 % 256;
	t[i + 2] = k / 256 / 256 % 256;
	t[i + 3] = k / 256 / 256 / 256;
}

static void	filehead(int fd, t_all *all)
{
	int		i;
	char	t[14];

	i = -1;
	while (++i < 14)
		t[i] = 0;
	t[0] = 66;
	t[1] = 77;
	t[10] = 54;
	add_to_bit(t, 2, all->res.y * all->res.x);
	write(fd, t, 14);
}

static void	infohead(int fd, t_all *all)
{
	int		i;
	char	t[40];

	i = -1;
	while (++i < 40)
		t[i] = 0;
	t[0] = 40;
	t[12] = 1;
	t[14] = 32;
	add_to_bit(t, 4, all->res.x);
	add_to_bit(t, 8, all->res.y);
	write(fd, t, 40);
}

static void	color_table(int fd, t_all *all)
{
	int	y;
	int	x;

	y = all->res.y;
	while (y--)
	{
		x = -1;
		while (++x < all->res.x)
			write(fd, (all->img.addr + (y * all->img.line_length
						+ x * (all->img.bits_per_pixel / 8))), 4);
	}
}

int	create_bmp(t_all *all)
{
	int	fd;

	fd = open(BMP, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd <= 0)
		errors2(10);
	filehead(fd, all);
	infohead(fd, all);
	color_table(fd, all);
	close(fd);
	return (0);
}
