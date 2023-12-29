/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/12/29 14:51:17 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "line.h"

static uint32_t	g_asset_index;

void	r_set_asset(uint32_t index)
{
	g_asset_index = index;
}

void	r_draw_line(uint32_t x, uint32_t *line, uint32_t len, uint32_t tex_x)
{
	mlx_texture_t	*asset;
	float			tex_step;
	float			tex_pos;
	int32_t			tex_y;
	uint32_t		color;

	tex_step = 1.0f * (float)TEXTURE_SIZE / (float)len;
	tex_pos = (line[0] - (float)(HEIGHT / 2) + (float)(len / 2)) * tex_step;
	asset = assets_get(g_asset_index);
	if (!asset)
		return ;
	while (line[0] < line[1])
	{
		tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
		tex_pos += tex_step;
		color = r_get_pixel(asset, tex_x, tex_y);
		mlx_put_pixel(r_get_buffer()->frame, x, line[0]++, color);
	}
}
