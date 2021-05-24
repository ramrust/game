/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:21 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:23 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

void	parse_sprite(t_all *all, int i, int j)
{
	int	l;

	l = 0;
	all->sprite.buf = (t_sprt *)malloc(sizeof(t_sprt) * all->sprite.count);
	if (all->sprite.buf == NULL)
		errors1(9);
	while (all->only_m[++i])
	{
		j = -1;
		while (all->only_m[i][++j])
		{
			if (all->only_m[i][j] == '2')
			{
				all->sprite.buf[l].y = (double)(i + 0.5);
				all->sprite.buf[l].x = (double)(j + 0.5);
				l++;
			}
		}
	}
}

int	rgb_to_int_c(t_all *all)
{
	if (all->C.r > 255)
		errors(3);
	if (all->C.g > 255)
		errors(3);
	if (all->C.b > 255)
		errors(3);
	return ((int)all->C.r * 65536 + (int)all->C.g * 256 + (int)all->C.b);
}

int	parse_player(t_all *all, int i, size_t j)
{
	if (!(all->only_m[i][j + 1]) || !(all->only_m[i + 1][j])
		|| !(all->only_m[i - 1][j]) || !(all->only_m[i][j - 1]))
		errors(5);
	if (ft_strchr("NSEW", all->only_m[i][j]))
		check_view(all, i, j);
	return (1);
}

void	valid_map(t_all *all, int i, int j)
{
	all->plr.fl = 0;
	while (all->only_m[++i])
	{
		j = 0;
		while (all->only_m[i][j])
		{
			if (ft_strchr("NSEW", all->only_m[i][j])
	|| all->only_m[i][j] == '0')
			{
				if ((parse_player(all, i, j)) != 1 && j++)
					errors1(8);
				j++;
			}
			else if (all->only_m[i][j] == '1' || all->only_m[i][j] == ' '
				|| all->only_m[i][j] == '\n')
				j++;
			else if (all->only_m[i][j] == '2')
			{
				all->sprite.count++;
				j++;
			}
		}
	}
	if (all->plr.fl == 0)
		errors1(8);
}

void	do_map(char **map, t_all *all, int j)
{
	int	i;

	i = 0;
	while (map[i] && i < j)
	{
		if (!map[i][0])
		{
			i++;
			continue ;
		}
		i++;
	}
	all->only_m = &map[i];
	all->sprite.count = 0;
	i = -1;
	valid_map(all, -1, 0);
}
