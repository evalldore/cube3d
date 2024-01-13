/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:42 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/07 19:58:00 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include <stdio.h>
#include <math.h>

static mlx_image_t	*g_floor;

static void put_pixel(uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	i;
	uint32_t	*pixels;
	
	(void)color;
	pixels = (uint32_t *)g_floor->pixels;
	i = (y * WIDTH) + x;
	pixels[i] = color;
}

void r_floor_draw(uint32_t	color, t_camera cam)
{
	t_ivec	offset;
	t_ivec	coord;
	t_fvec	world;
	t_fvec	rot;

	offset = (t_ivec){WIDTH / 2, 0};
	coord.y = 0;
	ft_memset(g_floor->pixels, 0, (WIDTH * (HEIGHT / 2)) * sizeof(uint32_t));
	while (coord.y < (HEIGHT / 2))
	{
		coord.x = -offset.x;
		while (coord.x < offset.x)
		{
			world.x = coord.x / (float)coord.y;
			world.y = 360.0f / (float)coord.y;
			rot.x = world.x * sin(cam.angle) - world.y * cos(cam.angle) - (cam.pos.x * 0.5f);
			rot.y = world.x * cos(cam.angle) + world.y * sin(cam.angle) + (cam.pos.y * 0.5f);
			if (rot.x < 0)
				rot.x = -rot.x + 1.0f;
			if (rot.y < 0)
				rot.y = -rot.y + 1.0f;
			if ((int)rot.x % 2 == (int)rot.y % 2)
				put_pixel(coord.x + offset.x, coord.y, color);
			else
				put_pixel(coord.x + offset.x, coord.y, r_calc_color(0, 255, 0, 255));
			coord.x++;
		}
		coord.y++;
	}
}

void	r_floor_init(mlx_t *mlx)
{
	g_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	//r_floor_draw(r_calc_color(0, 0, 255, 255));
	mlx_image_to_window(mlx, g_floor, 0, HEIGHT / 2);
}
