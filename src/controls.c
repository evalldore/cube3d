/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:58:18 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/21 14:59:22 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "player.h"
#include "utils.h"
#include "world.h"
#include "collision.h"
#define TURN_SPEED 5
#define SPEED 5

static void	set(uint32_t key, t_control *ctrl, bool toggle)
{
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

void	controls_keys(mlx_key_data_t keydata, void *param)
{
	t_player	*player;

	(void)param;
	player = player_get();
	if (keydata.action == MLX_PRESS)
		set(keydata.key, &player->ctrl, true);
	else if (keydata.action == MLX_RELEASE)
		set(keydata.key, &player->ctrl, false);
}

void	controls_mouse(t_fvec move)
{
	static t_fvec	last_mouse;
	t_player		*player;

	if (last_mouse.x == 0.0f && last_mouse.y == 0.0f)
		last_mouse = move;
	player = player_get();
	player->dir -= deg2rad((last_mouse.x - move.x) * 0.05f);
	last_mouse = move;
}

static t_fvec	move(t_fvec pos, float dir, t_fvec input, float dt)
{
	t_ivec	coll_res;
	t_fvec	vel_dir;

	vel_dir.x = cos(dir) * input.y + cos(dir + deg2rad(90.0f)) * input.x;
	vel_dir.y = sin(dir) * input.y + sin(dir + deg2rad(90.0f)) * input.x;
	vel_dir = fvec_normalize(vel_dir);
	coll_res = collision_check(pos, vel_dir);
	if (coll_res.x == 0)
		pos.x += vel_dir.x * SPEED * dt;
	if (coll_res.y == 0)
		pos.y += vel_dir.y * SPEED * dt;
	return (pos);
}

void	controls_tick(mlx_t *mlx)
{
	t_fvec			input;
	t_player		*player;

	player = player_get();
	input.x = -1.0f * (float)player->ctrl.left;
	input.x += 1.0f * (float)player->ctrl.right;
	input.y = -1.0f * (float)player->ctrl.down;
	input.y += 1.0f * (float)player->ctrl.up;
	player->pos = move(player->pos, player->dir, input, mlx->delta_time);
	if (player->ctrl.turn_right)
		player->dir = rotate(player->dir, TURN_SPEED * mlx->delta_time);
	else if (player->ctrl.turn_left)
		player->dir = rotate(player->dir, -TURN_SPEED * mlx->delta_time);
}
