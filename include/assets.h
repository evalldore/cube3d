/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:07:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 14:39:30 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# include <MLX42/MLX42.h>
# include <stdlib.h>
# define MAX_FRAMES 4
# define TEXTURE_SIZE 64

enum	e_asset
{
	ASSET_NONE,
	ASSET_WALL_NORTH,
	ASSET_WALL_EAST,
	ASSET_WALL_SOUTH,
	ASSET_WALL_WEST,
	MAX_ASSETS
};

mlx_texture_t	*assets_get(int32_t	asset);
void			assets_init(mlx_t *mlx);

#endif