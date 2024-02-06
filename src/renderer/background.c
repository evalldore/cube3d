/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:17:15 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/06 18:17:34 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "renderer.h"
#include "world.h"

static mlx_image_t	*g_background;

static uint32_t	calc_shade(uint32_t coordy, uint32_t colors[])
{
	uint8_t		result[4];
	float		shade_mul;
	float		rev_shade_mul;
	uint8_t		*grad_col[2];

	grad_col[0] = (uint8_t *)&colors[0];
	grad_col[1] = (uint8_t *)&colors[1];
	shade_mul = (float)coordy / (float)((HEIGHT / 2) - 1);
	rev_shade_mul = (float)fmax(1.0f - shade_mul, 0.0);
	result[0] = rev_shade_mul * grad_col[0][0] + (shade_mul * grad_col[1][0]);
	result[1] = rev_shade_mul * grad_col[0][1] + (shade_mul * grad_col[1][1]);
	result[2] = rev_shade_mul * grad_col[0][2] + (shade_mul * grad_col[1][2]);
	result[3] = 255;
	return (r_calc_color(result[0], result[1], result[2], result[3]));
}

static void	shade(mlx_image_t *img, uint32_t top_color, uint32_t bottom_color)
{
	t_ivec		coord;
	uint32_t	*pixels;
	uint32_t	colors[2];

	coord = (t_ivec){0, 0};
	pixels = (uint32_t *)img->pixels;
	colors[0] = top_color;
	colors[1] = bottom_color;
	while (coord.y < (HEIGHT / 2))
	{
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			mlx_put_pixel(img, coord.x, coord.y, calc_shade(coord.y, colors));
			coord.x++;
		}
		coord.y++;
	}
}

void	r_back_init(mlx_t	*mlx)
{
	uint32_t	top_color;
	uint32_t	bottom_color;
	t_world		*world;

	world = world_get();
	top_color = world->colors[1];
	bottom_color = r_calc_color(255, 255, 255, 255);
	g_background = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	shade(g_background, top_color, bottom_color);
	mlx_image_to_window(mlx, g_background, 0, 0);
}
