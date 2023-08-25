/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:35:40 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 22:37:32 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include "renderer.h"
#include "camera.h"
#include "ray.h"

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
	return (false);
}

void	world_draw(t_camera cam)
{
	uint32_t	i;
	t_fvec		planeDir;
	t_fvec		angleDir;
	t_ray		ray;

	planeDir = camera_get_plane(cam);
	angleDir = camera_get_direction(cam);
	i = 0;
	while (i < WIDTH)
	{
		float cameraX = 2.0f * (float)(i / HEIGHT) - 1.0f;
		ray.pos = cam.pos;
		ray.dir.x = angleDir.x + planeDir.x * cameraX;
		ray.dir.y = angleDir.y + planeDir.y * cameraX;
		ray.length = 16;
		ray.check = world_is_wall;
		ray_cast(&ray);
		i++;
	}
}
