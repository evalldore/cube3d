/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:35:40 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/25 16:29:20 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include <MLX42/MLX42.h>
#include "renderer.h"
#include "ray.h"
#include "world.h"
#include "libft.h"

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
	float		line_h;
	float		line_o;

	line_h = (HEIGHT >> 1) - ((HEIGHT >> 1) / result.dist);
	line_o = HEIGHT - line_h;
	color = r_color(255, 0, 0, 255);
	if (result.norm.x != 0)
		color = r_color(100, 0, 0, 255);
	if (line_o < HEIGHT)
		mlx_put_pixel(r_get_buffer(), x, (uint32_t)line_o, color);
}

void	world_draw(t_camera cam)
{
	uint32_t	i;
	t_fvec		plane;
	t_fvec		dir;
	t_ray		ray;
	t_hit		result;

	i = 0;
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	while (i < WIDTH)
	{
		float cameraX = 2.0f * ((float)i / HEIGHT) - 1.0f;
		ray.pos = cam.pos;
		ray.dir.x = dir.x + plane.x * cameraX;
		ray.dir.y = dir.y + plane.y * cameraX;
		ray.length = 16;
		ray.check = world_is_wall;
		result = ray_cast(&ray);
		if (result.collide)
			draw_line(i, result);
		i++;
	}
}
