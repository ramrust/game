/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrike <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:20:04 by rulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:20:06 by rulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsin.h"

void	morelines(t_all *all, char **map, int j)
{
	if (all->res.keys < 8)
		errors(2);
	do_map(map, all, j);
}

char	**create_map(t_list **head, int size, int i, int save)
{
	char	**map;
	t_list	*temp;
	t_all	*all;
	int		j;

	temp = *head;
	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
		return (map);
	all = malloc(sizeof(t_all));
	if (all == NULL)
		return (map);
	while (temp)
	{
		map[++i] = temp->content;
		temp = temp->next;
	}
	all->save = 0;
	if (save == 1)
		all->save = 1;
	j = pars_map(map, all, 0);
	morelines(all, map, j);
	parse_sprite(all, -1, 0);
	print_map(all);
	return (map);
}

static int	open_file(char *name, int *fd, int i)
{
	if (!name)
		errors(4);
	*fd = open(name, O_RDONLY);
	if (*fd <= 0)
		errors(4);
	while (name[i] != '.' && name[i])
		i++;
	if (!name[i] || (ft_strncmp(&name[i], ".cub\0", 5)) != 0)
		errors(5);
	return (1);
}

void	parser(int *fd, int save)
{
	char	*line;
	t_list	*head;
	int		j;
	int		i;

	line = NULL;
	head = NULL;
	j = 0;
	i = 0;
	j = (get_next_line(*fd, &line, 1));
	while (j > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		j = (get_next_line(*fd, &line, 1));
		i++;
	}
	if (j == 0 && i ==0)
	{
		close (*fd);
		errors(4);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	create_map(&head, ft_lstsize(head), -1, save);
	free(line);
	close(*fd);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	save;

	save = 0;
	if (argc > 3)
		errors1(6);
	if (open_file(argv[1], &fd, 0) != 1)
		errors1(7);
	if (argv[2] && (ft_strncmp(argv[2], "--save", 7) == 0))
		save = 1;
	if (argc == 3 && save != 1)
		errors2(11);
	parser(&fd, save);
	return (0);
}
