/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:06:31 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/09 15:14:40 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static mlx_texture_t	*g_assets[MAX_ASSETS];

static bool	assets_load(mlx_t *mlx, int32_t asset, const char *path)
{
	mlx_texture_t	*texture;

	(void)mlx;
	texture = mlx_load_png(path);
	if (!texture)
		return (false);
	g_assets[asset] = texture;
	return (true);
}

mlx_texture_t	*assets_get(int32_t	asset)
{
	if (asset <= ASSET_NONE || asset >= MAX_ASSETS)
		return (NULL);
	return (g_assets[asset]);
}

bool	assets_init(mlx_t *mlx, char *paths[])
{
	if (!assets_load(mlx, ASSET_WALL_NORTH, paths[0]))
		return (false);
	if (!assets_load(mlx, ASSET_WALL_SOUTH, paths[1]))
		return (false);
	if (!assets_load(mlx, ASSET_WALL_WEST, paths[2]))
		return (false);
	if (!assets_load(mlx, ASSET_WALL_EAST, paths[3]))
		return (false);
	return (true);
}
