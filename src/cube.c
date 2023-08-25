/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 22:13:21 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cube.h"
#include "renderer.h"
#include "entities.h"

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
	mlx_t		*mlx;
	t_comp_pos	*pos;

	r_clear();
	mlx = param;
	(void)mlx;
	ecs_iterate(sys_controls, param);
	pos = ecs_comp_get(g_player, COMP_POS);
	mlx_put_pixel(r_get_buffer(), pos->curr.x, pos->curr.y, r_color(255, 0, 0, 255));
}

void	c_exit(void)
{

}
