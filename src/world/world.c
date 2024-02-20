/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:35:40 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/20 18:29:55 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "world.h"
#include "assets.h"
#include "libft.h"
#include "parse.h"

static int is_valid(void)
{
	t_world *world;
	int i;
	
	world = world_get();
	if (world->data == NULL)
		return (printf("Error\nNo map!\n"));
	i = 0;
	while (i < 4)
	{
		if (world->assets[i] == NULL)
			return (printf("Error\nMissing asset!\n"));
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if ((u_int8_t)world->colors[i] == 0)
			return (printf("Error\nMissing color!\n"));
		i++;
	}
	if (world->start.coords.x == 0 && world->start.coords.y == 0)
		return (printf("Error\nMissing start position!\n"));
	return (0);
}

t_world	*world_get(void)
{
	static t_world	world;

	return (&world);
}

bool	world_init(mlx_t *mlx, char *path)
{
	t_world		*world;
	
	if (check_path(path))
		return (false);
	if (is_valid())
		return (false);
	world = world_get();
	if (!assets_init(mlx, world->assets))
		return (false);
	return (true);
}

bool	world_is_wall(t_uvec check)
{
	t_world		*world;

	world = world_get();
	if (check.x >= world->size.x)
		check.x = world->size.x - 1;
	if (check.y >= world->size.y)
		check.y = world->size.y - 1;
	return (world->data[check.y][check.x] == '1');
}
