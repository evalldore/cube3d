/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:42 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/16 17:50:53 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include <stdio.h>
#include <math.h>

static mlx_image_t	*g_floor;

void r_floor_draw(uint32_t	color, t_camera cam)
{
	t_ivec		coord;
	t_fvec		dir;
	t_fvec		plane;
	t_fvec		ray_dir[2];
	t_fvec		floor_step;
	t_fvec		floor;
	float		dist;

	coord.y = 0;
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	ft_memset(g_floor->pixels, 0, (WIDTH * (HEIGHT / 2)) * sizeof(uint32_t));
	while (coord.y < HEIGHT / 2)
	{
		ray_dir[0] = (t_fvec){dir.x - plane.x, dir.y - plane.y};
		ray_dir[1] = (t_fvec){dir.x + plane.x, dir.y + plane.y};
		dist = (float)(HEIGHT / 2) / (float)((coord.y + HEIGHT / 2) - HEIGHT / 2);
		floor_step = (t_fvec){dist * (ray_dir[1].x - ray_dir[0].x) / WIDTH, dist * (ray_dir[1].y - ray_dir[0].y) / WIDTH};
		floor = (t_fvec){cam.pos.x + dist * ray_dir[0].x, cam.pos.y + dist * ray_dir[0].y};
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			if ((uint32_t)floor.x % 2 == (uint32_t)floor.y % 2)
				mlx_put_pixel(g_floor, coord.x, coord.y, color);
			floor.x += floor_step.x;
			floor.y += floor_step.y;
			coord.x++;
		}
		coord.y++;
	}
}

void	r_floor_init(mlx_t *mlx)
{
	g_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	mlx_image_to_window(mlx, g_floor, 0, HEIGHT / 2);
}
