/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/26 00:36:32 by niceguy          ###   ########.fr       */
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

static uint32_t g_player;

bool	c_init(void *params)
{
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

	r_clear(r_color(0, 0, 0, 255));
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
