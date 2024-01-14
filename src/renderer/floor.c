/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:42 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/14 00:27:50 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include <stdio.h>
#include <math.h>

static mlx_image_t	*g_floor;

/*

for(int y = 0; y < h; y++)
    {
      // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
      float rayDirX0 = dirX - planeX;
      float rayDirY0 = dirY - planeY;
      float rayDirX1 = dirX + planeX;
      float rayDirY1 = dirY + planeY;

      // Current y position compared to the center of the screen (the horizon)
      int p = y - screenHeight / 2;

      // Vertical position of the camera.
      float posZ = 0.5 * screenHeight;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
      float rowDistance = posZ / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
      float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / screenWidth;
      float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / screenWidth;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
      float floorX = posX + rowDistance * rayDirX0;
      float floorY = posY + rowDistance * rayDirY0;

      for(int x = 0; x < screenWidth; ++x)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        int cellX = (int)(floorX);
        int cellY = (int)(floorY);

        // get the texture coordinate from the fractional part
        int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
        int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

        floorX += floorStepX;
        floorY += floorStepY;

        // choose texture and draw the pixel
        int floorTexture = 3;
        int ceilingTexture = 6;
        Uint32 color;

        // floor
        color = texture[floorTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[y][x] = color;

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        color = texture[ceilingTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[screenHeight - y - 1][x] = color;
      }
    }

*/

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
	t_ivec		coord;
	t_fvec		dir;
	t_fvec		plane;
	t_fvec		ray_dir[2];
	t_fvec		floor_step;
	t_fvec		floor;
	float		dist;

	coord.y = HEIGHT;
	plane = camera_get_plane(cam);
	dir = camera_get_direction(cam);
	ft_memset(g_floor->pixels, 0, (WIDTH * (HEIGHT / 2)) * sizeof(uint32_t));
	while (coord.y > HEIGHT / 2)
	{
		ray_dir[0] = (t_fvec){dir.x - plane.x, dir.y - plane.y};
		ray_dir[1] = (t_fvec){dir.x + plane.x, dir.y + plane.y};
		dist = (float)(HEIGHT / 2) / (float)(coord.y - HEIGHT / 2);
		floor_step = (t_fvec){dist * (ray_dir[1].x - ray_dir[0].x) / WIDTH, dist * (ray_dir[1].y - ray_dir[0].y) / WIDTH};
		floor = (t_fvec){cam.pos.x + dist * ray_dir[0].x, cam.pos.y + dist * ray_dir[0].y};
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			if ((uint32_t)floor.x % 2 == (uint32_t)floor.y % 2)
				put_pixel(coord.x, coord.y - HEIGHT / 2, color);
			floor.x += floor_step.x;
			floor.y += floor_step.y;
			coord.x++;
		}
		coord.y--;
	}
}

void	r_floor_init(mlx_t *mlx)
{
	g_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	//r_floor_draw(r_calc_color(0, 0, 255, 255));
	mlx_image_to_window(mlx, g_floor, 0, HEIGHT / 2);
}
