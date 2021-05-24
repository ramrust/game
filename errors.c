/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:18:10 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:18:20 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsin.h"

void	errors(int flag)
{
	if (flag == 1)
	{
		write(1, "Error\nwrong resolution format\n", 31);
		exit(1);
	}
	if (flag == 2)
	{
		write(1, "Error\nwrong parsing format\n", 28);
		exit(2);
	}
	if (flag == 3)
	{
		write(1, "Error\nwrong floor or ceiling format\n", 37);
		exit(3);
	}
	if (flag == 4)
	{
		write(1, "Error\nno map\n", 14);
		exit(4);
	}
	if (flag == 5)
	{
		write(1, "Error\nwrong map format\n", 24);
		exit(5);
	}
}

void	errors1(int flag)
{
	if (flag == 6)
	{
		write(1, "Error\nwrong arguments count\n", 29);
		exit(6);
	}
	if (flag == 7)
	{
		write(1, "Error\ncan not open file\n", 25);
		exit(7);
	}
	if (flag == 8)
	{
		write(1, "Error\nplayer problems\n", 23);
		exit(8);
	}
	if (flag == 9)
	{
		write(1, "Error\nin memmory\n", 18);
		exit(9);
	}
	if (flag == 15)
	{
		write(1, "Error\nin MLX textures\n", 23);
		exit(15);
	}
}

void	errors2(int flag)
{
	if (flag == 10)
	{
		write(1, "Error\nsaving problem\n", 22);
		exit(10);
	}
	if (flag == 11)
	{
		write(1, "Error\nwrong argument\n", 22);
		exit(11);
	}
	if (flag == 12)
	{
		write(1, "Error\nkeys problem\n", 20);
		exit(12);
	}
}
