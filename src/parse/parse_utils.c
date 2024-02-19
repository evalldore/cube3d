/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:04:12 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/19 17:29:21 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int floodf(char **map, size_t x, size_t y)
{
	t_world *world;

	world = world_get();
	if (x >= world->size.x || y >= world->size.y)
		return (1);
	if (map[y][x] == 'c' || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'x')
		return (1);
	map[y][x] = 'c';
	if (floodf(map, x, y + 1))
		return (1);
	if (floodf(map, x, y - 1))
		return (1);
	if (floodf(map, x + 1, y))
		return (1);
	if (floodf(map, x - 1, y))
		return (1);
	return (0);
}

static void start_dir(char c)
{
	t_world *world;

	world = world_get();
	if (c == 'N')
		world->start.dir = 270.0f;
	else if (c == 'S')
		world->start.dir = 90.0f;
	else if (c == 'W')
		world->start.dir = 180.0f;
	else if (c == 'E')
		world->start.dir = 0.0f;
}

static char **copy_map(char **map)
{
	t_world *world;
	char **cpy;
	size_t i;
	size_t j;

	world = world_get();
	cpy = (char **)ft_calloc(world->size.y, sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < world->size.y)
	{
		cpy[i] = (char *)ft_calloc((world->size.x + 1), sizeof(char));
		if (cpy[i] == NULL)
			return (NULL);
		j = 0;
		while (j < world->size.x)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'x')
				cpy[i][j] = '0';
			else
				cpy[i][j] = map[i][j];
			j++;
		}
		cpy[i][j] = '\0'; 
		i++;
	}
	return (cpy);
}

int start_pos(char **map)
{
	size_t i;
	size_t j;
	t_world *world;

	world = world_get();
	i = 0;
	while (i < world->size.y)
	{
		j = 0;
		while (j < world->size.x)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'x')
			{
				world->start.coords = (t_fvec){j, i};
				start_dir(map[i][j]);
			}
			j++;
		}
		i++;
	}
	world->data = (uint8_t **)map;
	return (floodf(copy_map(map), world->start.coords.x, world->start.coords.y));
}
