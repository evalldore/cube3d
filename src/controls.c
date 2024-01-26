/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:58:18 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/26 15:44:34 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "entities.h"
#include "utils.h"
#include "world.h"
#include "collision.h"
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
	t_ivec	coll_res;
	t_fvec	vel_dir;
	t_fvec	dir_vec[2];

	dir_vec[0] = (t_fvec){cos(dir), sin(dir)};
	dir_vec[1] = (t_fvec){cos(dir + deg2rad(90.0f)), sin(dir + deg2rad(90.0f))};
	vel_dir.x = dir_vec[0].x * input.y;
	vel_dir.y = dir_vec[0].y * input.y;
	vel_dir.x += dir_vec[1].x * input.x;
	vel_dir.y += dir_vec[1].y * input.x;
	coll_res = collision_check(pos, vel_dir);
	if (coll_res.x == 0)
		pos.x += vel_dir.x * SPEED * dt;
	if (coll_res.y == 0)
		pos.y += vel_dir.y * SPEED * dt;
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
