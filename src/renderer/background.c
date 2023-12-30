/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:17:15 by evallee-          #+#    #+#             */
/*   Updated: 2023/12/29 19:17:30 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "renderer.h"

static mlx_image_t	*g_background;

static uint32_t calc_shade(uint32_t coordy, uint32_t top_color, uint32_t bottom_color)
{
	uint8_t		color[4];
	float		shade_mul;
	float		rev_shade_mul;
	uint8_t		*color_1; 
	uint8_t		*color_2;

	color_1 = (uint8_t *)&top_color;
	color_2 = (uint8_t *)&bottom_color;
	shade_mul = (float)coordy / (float)((HEIGHT / 2) - 1);
	rev_shade_mul = (float)fmax(1.0f - shade_mul, 0.0);
	color[0] = rev_shade_mul * color_1[0] + (shade_mul * color_2[0]);
	color[1] = rev_shade_mul * color_1[1] + (shade_mul * color_2[1]);
	color[2] = rev_shade_mul * color_1[2] + (shade_mul * color_2[2]);
	color[3] = 255;
	return (r_calc_color(color[0], color[1], color[2], color[3]));
}

static void	shade(mlx_image_t *img, uint32_t top_color, uint32_t bottom_color)
{
	t_ivec		coord;
	uint32_t	i;
	uint32_t	*pixel;

	i = 0;
	coord = (t_ivec){0, 0};
	while (coord.y < (HEIGHT / 2))
	{
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			i = ((coord.y * WIDTH) + coord.x) * sizeof(uint32_t);
			pixel = (uint32_t *)&img->pixels[i];
			*pixel = calc_shade(coord.y, top_color, bottom_color);
			coord.x++;
		}
		coord.y++;
	}
}

void	r_back_init(mlx_t	*mlx)
{
	uint32_t	top_color;
	uint32_t	bottom_color;

	top_color = r_calc_color(255, 0, 0, 255);
	bottom_color = r_calc_color(255, 255, 255, 255);
	g_background = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	shade(g_background, top_color, bottom_color);
	mlx_image_to_window(mlx, g_background, 0, 0);
}
