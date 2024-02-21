/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:50 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:17:43 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radar.h"

static mlx_image_t	**get_image(void)
{
	static mlx_image_t	*image;

	return (&image);
}

static void	draw_square(uint32_t x, uint32_t y, uint32_t size, uint32_t color)
{
	uint32_t	i;

	i = 0;
	while (i < (size * size))
	{
		mlx_put_pixel(*get_image(), x + (i % size), y + (i / size), color);
		i++;
	}
}

void	radar_draw(t_world *world, t_fvec pos)
{
	t_uvec		coords;
	uint32_t	color;
	t_uvec		unit_pos;
	mlx_image_t	*image;

	image = *get_image();
	ft_memset(image->pixels, 0, image->width * image->height);
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
			unit_pos = (t_uvec){coords.x * UNIT_SIZE, coords.y * UNIT_SIZE};
			draw_square(unit_pos.x, unit_pos.y, UNIT_SIZE, color);
			coords.y++;
		}
		coords.x++;
	}
}

void	radar_init(mlx_t	*mlx)
{
	t_world		*world;
	t_uvec		radar_size;
	mlx_image_t	*image;

	world = world_get();
	radar_size = (t_uvec){world->size.x * UNIT_SIZE, world->size.y * UNIT_SIZE};
	image = mlx_new_image(mlx, radar_size.x, radar_size.y);
	if (!image)
		return ;
	mlx_image_to_window(mlx, image, 15, 15);
	*get_image() = image;
}
