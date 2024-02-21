/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/21 15:16:49 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cube.h"
#include "renderer.h"
#include "player.h"
#include "world.h"
#include "camera.h"
#include "assets.h"
#include "utils.h"
#include "radar.h"
#include "parse.h"

bool	c_init(mlx_t *mlx, char *path)
{
	t_world		*world;
	t_player	*player;

	if (!world_init(mlx, path))
		return (false);
	world = world_get();
	r_init(mlx);
	if (BONUS)
		radar_init(mlx);
	player = player_get();
	player->pos = world->start.coords;
	player->dir = deg2rad(world->start.dir);
	return (true);
}

void	c_keys(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (mlx_close_window(mlx));
	controls_keys(keydata, param);
}

void	c_mouse(double xpos, double ypos, void *param)
{
	(void)param;
	if (BONUS)
		controls_mouse((t_fvec){(float)xpos, (float)ypos});
}

void	c_tick(void *param)
{
	t_camera	cam;
	t_player	*player;
	t_world		*world;

	player = player_get();
	world = world_get();
	r_clear(r_calc_color(0, 0, 0, 0));
	controls_tick(param);
	cam.pos = player->pos;
	cam.angle = player->dir;
	world_draw(cam);
	if (BONUS)
		radar_draw(world, player->pos);
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
	mlx_terminate(mlx);
	if (!return_val)
		printf("exitting cub3D\n");
	return (return_val);
}
