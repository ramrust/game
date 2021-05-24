/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:12 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:14 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

void	parse_r(char *map, t_all *all, int j)
{
	if (all->res.x != 0 || all->res.y != 0)
		errors(1);
	all->res.x = ft_atoi(&map[j]);
	j = skip_space(map, j);
	while (ft_isdigit(map[j]))
		j++;
	if (map[j] != ' ')
		errors(1);
	j = skip_space(map, j);
	all->res.y = ft_atoi(&(map[j]));
	while (ft_isdigit(map[j]))
		j++;
	if (map[j] != '\0')
		errors(1);
	if ((all->res.x) <= 0 || (all->res.y) <= 0)
		errors(1);
	if (all->res.x > 2560)
		all->res.x = 2560;
	if (all->res.y > 1440)
		all->res.y = 1440;
	all->res.keys++;
}

void	parse_f(char *map, t_all *all, int j)
{
	checkcolorf(all);
	while (map[++j])
		if ((map[j] > '9' || map[j] < '0')
			&& (map[j] != ',' && map[j] != ' '))
			errors(3);
	if (j < 5)
		errors(3);
	j = skip_space(map, 1);
	all->F.r = ft_atoi(&map[j]);
	while (ft_isdigit(map[j]))
		j++;
	if (map[j] != ',')
		errors(3);
	j = skip_space(map, (j + 1));
	all->F.g = ft_atoi(&map[j]);
	while (ft_isdigit(map[j]))
		j++;
	if ((map[j]) != ',')
		errors(3);
	j = skip_space(map, j + 1);
	all->F.b = ft_atoi(&map[j]);
	all->res.keys++;
	checkcolorfa(all);
}

void	parse_c(char *map, t_all *all, int j)
{
	checkcolorc(all);
	while (map[++j])
		if ((map[j] > '9' || map[j] < '0')
			&& (map[j] != ',' && map[j] != ' '))
			errors(3);
	if (j < 5)
		errors(3);
	j = skip_space(map, 1);
	all->C.r = ft_atoi(&map[j]);
	while (ft_isdigit(map[j]))
		j++;
	if (map[j] != ',')
		errors(3);
	j = skip_space(map, (j + 1));
	all->C.g = ft_atoi(&map[j]);
	while (ft_isdigit(map[j]))
		j++;
	if ((map[j]) != ',')
		errors(3);
	j = skip_space(map, j + 1);
	all->C.b = ft_atoi(&map[j]);
	checkcolorca(all);
	all->res.keys++;
}

void	parsif(char **map, t_all *all, int i)
{
	if (!(ft_strncmp(map[i], "R ", 2)))
		parse_r(map[i], all, 1);
	else if (!(ft_strncmp((map[i]), "NO ", 3)))
		parsNo(map, all, i);
	else if ((ft_strncmp((map[i]), "WE ", 3) == 0))
		parsWe(map, all, i);
	else if ((ft_strncmp((map[i]), "EA ", 3) == 0))
		parsEa(map, all, i);
	else if ((ft_strncmp((map[i]), "SO ", 3) == 0))
		parsSo(map, all, i);
	else if ((ft_strncmp((map[i]), "F ", 2) == 0))
		parse_f(map[i], all, 1);
	else if ((ft_strncmp(map[i], "S ", 2) == 0))
		parsS(map, all, i);
	else if ((ft_strncmp(map[i], "C", 1) == 0))
		parse_c(map[i], all, 1);
}

int	pars_map(char **map, t_all *all, int i)
{	
	keysinit(all);
	while (map[i] && map[i][0] != '1' && map[i][0] != '0' && map[i][0] != ' ')
	{
		if (!map[i][0])
		{	
			i++;
			continue ;
		}
		parsif(map, all, i);
		i++;
	}
	return (i);
}
