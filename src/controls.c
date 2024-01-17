/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:58:18 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/16 22:07:04 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "entities.h"
#include "utils.h"
#include "world.h"
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

void		sys_controls_mouse(t_fvec move)
{
	static t_fvec	last_mouse;
	t_comp_ctrl		*ctrl;
	t_comp_dir		*dir;
	uint32_t		ent;

	ent = 0;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		dir = ecs_comp_get(ent, COMP_DIR);
		if (ctrl && dir)
			dir->curr -= deg2rad((last_mouse.x - move.x) * 0.1f);
		ent++;
	}
	last_mouse = move;
}

static t_fvec	move(t_fvec pos, float dir, float scale, float dt)
{
	t_uvec	check;

	check.x = (uint32_t)(pos.x + cos(dir) * (0.5f * scale));
	check.y = (uint32_t)pos.y;
	if (world_is_wall(check) == 0)
		pos.x += (cos(dir) * SPEED * dt) * scale;
	check.x = (uint32_t)pos.x;
	check.y = (uint32_t)(pos.y + sin(dir) * (0.5f * scale));
	if (world_is_wall(check) == 0)
		pos.y += (sin(dir) * SPEED * dt) * scale;
	if (pos.x < 0.0f)
		pos.x = 0.0f;
	if (pos.y < 0.0f)
		pos.y = 0.0f;
	return (pos);
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
		pos->curr = move(pos->curr, dir->curr, 1.0, mlx->delta_time);
	if (ctrl->down)
		pos->curr = move(pos->curr, dir->curr, -1.0, mlx->delta_time);
	if (ctrl->right)
		dir->curr = rotate(dir->curr, TURN_SPEED * mlx->delta_time);
	if (ctrl->left)
		dir->curr = rotate(dir->curr, -TURN_SPEED * mlx->delta_time);
}
