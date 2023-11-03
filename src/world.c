/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:35:40 by niceguy           #+#    #+#             */
/*   Updated: 2023/11/03 16:01:49 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include <MLX42/MLX42.h>
#include "renderer.h"
#include "ray.h"
#include "world.h"
#include "libft.h"

static float		g_z_buffer[WIDTH];
static uint32_t		g_world_w = 16;
static uint32_t		g_world_h = 16;
static uint32_t		g_map[][16] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 6, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 6, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	world_init(void)
{
	(void)g_map;
}

bool	world_is_wall(t_uvec check)
{
	if (check.x < g_world_w && check.y < g_world_h)
		return (g_map[check.y][check.x] != 0);
	return (true);
}

static void	draw_line(uint32_t x, t_hit result)
{
	uint32_t	color;
	uint32_t	line_h;
	int32_t		line[2];
	uint32_t	y;
	float		fade;

	fade = fmax(1.0f - (result.dist / 11.0f), 0.0f);
	color = r_color(100 * fade, 0, 0, 255);
	if (result.norm.x < 0)
		color = r_color(0, 100 * fade, 0, 255);
	if (result.norm.y > 0)
		color = r_color(100 * fade, 100 * fade, 0, 255);
	if (result.norm.y < 0)
		color = r_color(0, 0, 100 * fade, 255);
	line_h = (int)(HEIGHT / result.dist);
	line[0] = -(line_h >> 1) + (HEIGHT >> 1);
	if (line[0] < 0) 
		line[0] = 0;
	line[1] = (line_h >> 1) + (HEIGHT >> 1);
	if (line[1] >= HEIGHT)
		line[1] = HEIGHT - 1;
	y = line[0];
	while (y < line[1])
		mlx_put_pixel(r_get_buffer(), x, y++, color);
	g_z_buffer[x] = result.dist;
}

static void	clear(void)
{
	uint32_t	x;

	x = 0;
	while (x < WIDTH)
		g_z_buffer[x++] = INFINITY;
}

void	world_draw(t_camera cam)
{
	uint32_t	x;
	t_fvec		plane;
	t_fvec		dir;
	t_ray		ray;
	t_hit		result;

	x = 0;
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	clear();
	while (x < WIDTH)
	{
		float cameraX = 2.0f * ((float)x / WIDTH) - 1.0f;
		ray.pos = cam.pos;
		ray.dir.x = dir.x + plane.x * cameraX;
		ray.dir.y = dir.y + plane.y * cameraX;
		ray.length = 18;
		ray.check = world_is_wall;
		result = ray_cast(&ray);
		if (result.collide)
			draw_line(x, result);
		x++;
	}
}
