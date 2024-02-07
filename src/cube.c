/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/07 15:29:56 by evallee-         ###   ########.fr       */
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

static uint32_t	g_player;

bool	c_init(void *params, char *path)
{
	t_world	*world;
	if (!world_init(params, path))
		return (false);
	world = world_get();
	r_init(params);
	ents_init();
	g_player = ents_player(world->start.coords, deg2rad(world->start.dir));
	return (true);
}

void	c_keys(mlx_key_data_t keydata, void *param)
{
	mlx_t*		mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return mlx_close_window(mlx);
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
}

void	c_exit(void)
{
	ecs_remove(g_player);
	printf("exitting cub3D\n");
}