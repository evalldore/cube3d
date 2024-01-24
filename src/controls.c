/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:58:18 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/24 16:56:42 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "entities.h"
#include "utils.h"
#include "world.h"
#define TURN_SPEED 5
#define SPEED 5

static void	set(uint32_t key, t_comp_ctrl *ctrl, bool toggle)
{
	t_comp_ctrl	last;

	last = *ctrl;
	if (key == MLX_KEY_W)
		ctrl->up = toggle;
	if (key == MLX_KEY_S)
		ctrl->down = toggle;
	if (key == MLX_KEY_A)
		ctrl->left = toggle;
	if (key == MLX_KEY_D)
		ctrl->right = toggle;
	if (key == MLX_KEY_LEFT)
		ctrl->turn_left = toggle;
	if (key == MLX_KEY_RIGHT)
		ctrl->turn_right = toggle;
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

void	sys_controls_mouse(t_fvec move)
{
	static t_fvec	last_mouse;
	t_comp_ctrl		*ctrl;
	t_comp_dir		*dir;
	uint32_t		ent;

	if (last_mouse.x == 0.0f && last_mouse.y == 0.0f)
		last_mouse = move;
	ent = 0;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		dir = ecs_comp_get(ent, COMP_DIR);
		if (ctrl && dir)
			dir->curr -= deg2rad((last_mouse.x - move.x) * 0.05f);
		ent++;
	}
	last_mouse = move;
}

static t_fvec	move(t_fvec pos, float dir, t_fvec input, float dt)
{
	t_uvec	check;
	t_fvec	vel;

	vel.x = (cos(dir) * SPEED * dt) * input.y;
	vel.y = (sin(dir) * SPEED * dt) * input.y;
	vel.x += (cos(dir + deg2rad(90.0f)) * SPEED * dt) * input.x;
	vel.y += (sin(dir + deg2rad(90.0f)) * SPEED * dt) * input.x;
	check.x = (uint32_t)(pos.x + cos(dir) * (0.5f * input.y));
	check.y = (uint32_t)(pos.y + sin(dir + deg2rad(90.0f)) * (0.5f * input.x));
	if (world_is_wall(check) == 0)
		pos.x += vel.x;
	check.x = (uint32_t)(pos.x + cos(dir + deg2rad(90.0f)) * (0.5f * input.x));
	check.y = (uint32_t)(pos.y + sin(dir) * (0.5f * input.y));
	if (world_is_wall(check) == 0)
		pos.y += vel.y;
	return (pos);
}

void	sys_controls(uint32_t ent, va_list args)
{
	mlx_t			*mlx;
	t_comp_ctrl		*ctrl;
	t_comp_pos		*pos;
	t_comp_dir		*dir;
	t_fvec			input;

	mlx = va_arg(args, void *);
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	pos = ecs_comp_get(ent, COMP_POS);
	dir = ecs_comp_get(ent, COMP_DIR);
	if (!ctrl || !pos || !dir)
		return ;
	input.x = -1.0f * (float)ctrl->left;
	input.x += 1.0f * (float)ctrl->right;
	input.y = -1.0f * (float)ctrl->down;
	input.y += 1.0f * (float)ctrl->up;
	pos->curr = move(pos->curr, dir->curr, input, mlx->delta_time);
	if (ctrl->turn_right)
		dir->curr = rotate(dir->curr, TURN_SPEED * mlx->delta_time);
	else if (ctrl->turn_left)
		dir->curr = rotate(dir->curr, -TURN_SPEED * mlx->delta_time);
}
