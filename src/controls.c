/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:58:18 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/25 14:30:46 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "entities.h"
#include "utils.h"
#define TURN_SPEED 5
#define SPEED 5

static bool	set(uint32_t key, t_comp_ctrl *ctrl, bool toggle)
{
	if (key == MLX_KEY_W)
	{
		ctrl->up = toggle;
		return (true);
	}
	if (key == MLX_KEY_S)
	{
		ctrl->down = toggle;
		return (true);
	}
	if (key == MLX_KEY_A)
	{
		ctrl->left = toggle;
		return (true);
	}
	if (key == MLX_KEY_D)
	{
		ctrl->right = toggle;
		return (true);
	}
	return (false);
}

void	sys_controls_keys(mlx_key_data_t keydata, void *param)
{
	t_comp_ctrl		*ctrl;
	uint32_t		ent;

	(void)param;
	ent = 0;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		if (keydata.action == MLX_PRESS)
			set(keydata.key, ctrl, true);
		else if (keydata.action == MLX_RELEASE)
			set(keydata.key, ctrl, false);
		ent++;
	}
}

static void	move(t_comp_pos *pos, float dir, float scale, float dt)
{
	pos->curr.x += (cos(dir) * SPEED * dt) * scale;
	pos->curr.y += (sin(dir) * SPEED * dt) * scale;
	if (pos->curr.x < 0.0f)
		pos->curr.x = 0.0f;
	if (pos->curr.y < 0.0f)
		pos->curr.y = 0.0f;
}

void	sys_controls(uint32_t ent, va_list args)
{
	mlx_t			*mlx;
	t_comp_ctrl		*ctrl;
	t_comp_pos		*pos;
	t_comp_dir		*dir;

	mlx = va_arg(args, void *);
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	pos = ecs_comp_get(ent, COMP_POS);
	dir = ecs_comp_get(ent, COMP_DIR);
	if (!ctrl || !pos || !dir)
		return ;
	if (ctrl->up)
		move(pos, dir->curr, 1.0, mlx->delta_time);
	if (ctrl->down)
		move(pos, dir->curr, -1.0, mlx->delta_time);
	if (ctrl->right)
		dir->curr = rotate(dir->curr, TURN_SPEED * mlx->delta_time);
	if (ctrl->left)
		dir->curr = rotate(dir->curr, -TURN_SPEED * mlx->delta_time);
}
