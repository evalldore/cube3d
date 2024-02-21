/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:01 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:26:46 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "renderer.h"

uint32_t	*r_get_asset(void)
{
	static uint32_t	asset_index;

	return (&asset_index);
}

void	r_set_asset(uint32_t index)
{
	*r_get_asset() = index;
}

static uint32_t	shade_line(uint32_t tex_x, uint32_t tex_y)
{
	mlx_texture_t	*asset;
	uint32_t		pixel;

	asset = assets_get(*r_get_asset());
	pixel = r_get_pixel(asset, tex_x, tex_y);
	return (pixel);
}

void	r_draw_line(uint32_t x, int line[], uint32_t len, uint32_t tex_x)
{
	float			tex_step;
	float			tex_pos;
	int32_t			tex_y;
	uint32_t		color;

	if (!assets_get(*r_get_asset()))
		return ;
	tex_step = 1.0f * (float)TEXTURE_SIZE / (float)len;
	tex_pos = (line[0] - (float)(HEIGHT / 2) + (float)(len / 2)) * tex_step;
	while (line[0] < line[1])
	{
		tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
		tex_pos += tex_step;
		color = shade_line(tex_x, tex_y);
		mlx_put_pixel(r_get_buffer()->frame, x, line[0]++, color);
	}
}
