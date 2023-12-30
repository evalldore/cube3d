/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 17:45:40 by evallee-         ###   ########.fr       */
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

static uint32_t	g_player;

bool	c_init(void *params)
{
	assets_init(params);
	r_init(params);
	ents_init();
	g_player = ents_player((t_fvec){2.0f, 2.0f}, 0.0f);
	return (true);
}

void	c_keys(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		c_exit();
		exit(0);
		return ;
	}
	sys_controls_keys(keydata, param);
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

}
