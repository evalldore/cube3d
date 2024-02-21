/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:42 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:24:55 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include "world.h"
#include <stdio.h>
#include <math.h>

static mlx_image_t	**get_image(void)
{
	static mlx_image_t	*floor;

	return (&floor);
}

static void	scan_line(t_camera cam, int32_t y, t_fvec dir, t_fvec plane)
{
	t_fvec		ray_dir[2];
	t_fvec		floor;
	t_fvec		floor_step;
	float		dist;
	uint32_t	x;

	ray_dir[0] = (t_fvec){dir.x - plane.x, dir.y - plane.y};
	ray_dir[1] = (t_fvec){dir.x + plane.x, dir.y + plane.y};
	dist = (float)(HEIGHT / 2) / (float)((y + HEIGHT / 2) - HEIGHT / 2);
	floor_step.x = dist * (ray_dir[1].x - ray_dir[0].x) / WIDTH;
	floor_step.y = dist * (ray_dir[1].y - ray_dir[0].y) / WIDTH;
	floor.x = cam.pos.x + dist * ray_dir[0].x;
	floor.y = cam.pos.y + dist * ray_dir[0].y;
	x = 0;
	while (x < WIDTH)
	{
		if ((uint32_t)floor.x % 2 == (uint32_t)floor.y % 2)
			mlx_put_pixel(*get_image(), x, y, world_get()->colors[0]);
		floor.x += floor_step.x;
		floor.y += floor_step.y;
		x++;
	}
}

void	r_floor_draw(t_camera cam)
{
	uint32_t	y;
	t_fvec		dir;
	t_fvec		plane;
	mlx_image_t	*floor;

	floor = *get_image();
	y = 0;
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	ft_memset(floor->pixels, 0, (WIDTH * (HEIGHT / 2)) * sizeof(uint32_t));
	while (y < HEIGHT / 2)
	{
		scan_line(cam, y, dir, plane);
		y++;
	}
}

void	r_floor_init(mlx_t *mlx)
{
	*get_image() = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	mlx_image_to_window(mlx, *get_image(), 0, HEIGHT / 2);
}
