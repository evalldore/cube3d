/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:32:45 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/06 16:45:07 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "ray.h"
#include "assets.h"
#include "renderer.h"

static uint32_t	calc_coord(t_hit result)
{
	float	coord;

	coord = 0.0f;
	if (result.norm.x != 0)
		coord = result.pos.y;
	else if (result.norm.y != 0)
		coord = result.pos.x;
	coord -= (float)floor((double)coord);
	return ((int)(coord * (float)(TEXTURE_SIZE)));
}

static void	draw_line(uint32_t x, t_hit result)
{
	uint32_t	asset_index;
	uint32_t	line_h;
	int32_t		line[2];

	asset_index = ASSET_WALL_SOUTH;
	if (result.norm.x < 0)
		asset_index = ASSET_WALL_WEST;
	if (result.norm.x > 0)
		asset_index = ASSET_WALL_EAST;
	if (result.norm.y < 0)
		asset_index = ASSET_WALL_NORTH;
	line_h = (int)(HEIGHT / result.dist);
	line[0] = -(line_h / 2) + (HEIGHT / 2);
	if (line[0] < 0) 
		line[0] = 0;
	line[1] = (line_h / 2) + (HEIGHT / 2);
	if (line[1] > HEIGHT)
		line[1] = HEIGHT;
	r_set_asset(asset_index);
	r_draw_line(x, line, line_h, calc_coord(result));
}

void	world_draw(t_camera cam)
{
	uint32_t	x;
	t_fvec		plane;
	t_fvec		dir;
	t_ray		ray;
	t_hit		result;

	r_floor_draw(world_get()->colors[0], cam);
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	x = 0;
	while (x < WIDTH)
	{
		float cameraX = 2.0f * ((float)x / WIDTH) - 1.0f;
		ray.pos = cam.pos;
		ray.dir.x = dir.x + plane.x * cameraX;
		ray.dir.y = dir.y + plane.y * cameraX;
		ray.length = DRAW_DISTANCE;
		ray.check = world_is_wall;
		result = ray_cast(&ray);
		if (result.collide)
			draw_line(x, result);
		x++;
	}
}
