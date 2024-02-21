/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/21 13:21:09 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cube.h"
#include "renderer.h"
#include "entities.h"
#include "world.h"
#include "camera.h"
#include "assets.h"
#include "utils.h"
#include "radar.h"
#include "parse.h"

static uint32_t	g_player;

bool	c_init(mlx_t *mlx, char *path)
{
	t_world	*world;

	if (!world_init(mlx, path))
		return (false);
	world = world_get();
	r_init(mlx);
	ents_init();
	radar_init(mlx);
	g_player = ents_player(world->start.coords, deg2rad(world->start.dir));
	return (true);
}

void	c_keys(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (mlx_close_window(mlx));
	sys_controls_keys(keydata, param);
}

void	c_mouse(double xpos, double ypos, void *param)
{
	(void)param;
	sys_controls_mouse((t_fvec){(float)xpos, (float)ypos});
}

void	c_tick(void *param)
{
	t_comp_pos	*pos;
	t_comp_dir	*dir;
	t_camera	cam;

	r_clear(r_calc_color(0, 0, 0, 0));
	ecs_iterate(sys_controls, param);
	pos = ecs_comp_get(g_player, COMP_POS);
	dir = ecs_comp_get(g_player, COMP_DIR);
	cam.pos = pos->curr;
	cam.angle = dir->curr;
	world_draw(cam);
	radar_draw(pos->curr);
}

int	c_exit(mlx_t *mlx, int return_val)
{
	t_world	*world;
	int		i;

	world = world_get();
	free_map((char **)world->data, 0, world->size.y);
	i = 0;
	while (i < 4)
	{
		if (world->assets[i])
			free(world->assets[i]);
		i++;
	}
	ecs_remove(g_player);
	mlx_terminate(mlx);
	if (!return_val)
		printf("exitting cub3D\n");
	return (return_val);
}
