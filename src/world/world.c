/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:35:40 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/19 17:09:16 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "world.h"
#include "assets.h"
#include "libft.h"
#include "parse.h"

static uint8_t		g_map[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 1, 0, 0, 0, 1,
	1, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 6, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 6, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

t_world		*world_get(void)
{
	static t_world	world;

	return (&world);
}

bool	world_init(mlx_t *mlx, char *path)
{
	t_world		*world;
	
	if (check_path(path))
		return (false);
	world = world_get();
	world->start.coords = (t_fvec){2.0f, 2.0f};
	world->start.dir = 270.0f;
	world->size.x = 16;
	world->size.y = 16;
	world->data = g_map;
	if (!assets_init(mlx, world->assets))
		return (false);
	return (true);
}

bool	world_is_wall(t_uvec check)
{
	t_world		*world;
	uint32_t	index;

	world = world_get();
	if (check.x >= world->size.x)
		check.x = world->size.x - 1;
	if (check.y >= world->size.y)
		check.y = world->size.y - 1;
	index = (check.y * world->size.x) + check.x;
	world = world_get();
	return (world->data[index] != 0);
}
