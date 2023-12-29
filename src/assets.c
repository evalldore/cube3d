/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:06:31 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 14:56:53 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static mlx_texture_t	*g_assets[MAX_ASSETS];

static void	assets_load(mlx_t *mlx, int32_t asset, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return ;
	g_assets[asset] = texture;
}

mlx_texture_t	*assets_get(int32_t	asset)
{
	if (asset <= ASSET_NONE || asset >= MAX_ASSETS)
		return (NULL);
	return (g_assets[asset]);
}

void	assets_init(mlx_t *mlx)
{
	assets_load(mlx, ASSET_WALL_NORTH, "assets/mossy.png");
	assets_load(mlx, ASSET_WALL_EAST, "assets/bluestone.png");
	assets_load(mlx, ASSET_WALL_SOUTH, "assets/greystone.png");
	assets_load(mlx, ASSET_WALL_WEST, "assets/purplestone.png");
}
