/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:06:31 by niceguy           #+#    #+#             */
/*   Updated: 2023/11/22 17:01:48 by evallee-         ###   ########.fr       */
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
	if (asset <= ASSET_NONE || asset >= MAX_ASSETS)
		return (NULL);
	return (g_assets.images[asset]);
}

void	assets_init(mlx_t *mlx)
{
	assets_load(mlx, ASSET_WALL, "assets/mossy.png");
}
