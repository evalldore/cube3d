/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:06:31 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 17:49:48 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static t_assets	g_assets;

static void	assets_load(mlx_t *mlx, int32_t asset, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return ;
	g_assets.textures[asset] = texture;
	g_assets.images[asset] = mlx_texture_to_image(mlx, texture);
}

mlx_image_t	*assets_get(int32_t	asset)
{
	return (g_assets.images[asset]);
}

void	assets_init(mlx_t *mlx)
{
	assets_load(mlx, ASSET_SAM_IDLE_R, "assets/idle_r.png");
	assets_load(mlx, ASSET_SAM_WALK_R_1, "assets/walk_r_1.png");
	assets_load(mlx, ASSET_SAM_WALK_R_2, "assets/walk_r_2.png");
	assets_load(mlx, ASSET_SAM_WALK_R_3, "assets/walk_r_3.png");
	assets_load(mlx, ASSET_SAM_IDLE_L, "assets/idle_l.png");
	assets_load(mlx, ASSET_SAM_WALK_L_1, "assets/walk_l_1.png");
	assets_load(mlx, ASSET_SAM_WALK_L_2, "assets/walk_l_2.png");
	assets_load(mlx, ASSET_SAM_WALK_L_3, "assets/walk_l_3.png");
}
