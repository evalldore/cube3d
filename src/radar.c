/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:50 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/08 17:31:28 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radar.h"

static mlx_image_t	*g_image;

static void draw_square(uint32_t x, uint32_t y, uint32_t size, uint32_t color)
{
	uint32_t	i;

	i = 0;
	while (i < (size * size))
	{
		mlx_put_pixel(g_image, x + (i % size), y + (i / size), color);
		i++;
	}
}

void radar_draw(t_fvec pos)
{
	t_uvec		coords;
	uint32_t	color;
	t_world		*world;

	world = world_get();
	ft_memset(g_image->pixels, 0, g_image->width * g_image->height);
	coords = (t_uvec){0, 0};
	while (coords.x < world->size.x)
	{
		coords.y = 0;
		while (coords.y < world->size.y)
		{
			color = r_calc_color(255, 255, 255, 255);
			if (coords.x == (uint32_t)pos.x && coords.y == (uint32_t)pos.y)
				color = r_calc_color(255, 255, 0, 255);
			else if (!world_is_wall(coords))
				color = r_calc_color(55, 55, 55, 255);
			draw_square(coords.x * UNIT_SIZE, coords.y * UNIT_SIZE, UNIT_SIZE, color);
			coords.y++;
		}
		coords.x++;
	}
}

void radar_init(mlx_t	*mlx)
{
	t_world	*world;

	world = world_get();
	g_image = mlx_new_image(mlx, world->size.x * UNIT_SIZE, world->size.y * UNIT_SIZE);
	if (!g_image)
		return;
	mlx_image_to_window(mlx, g_image, 15, 15);
}