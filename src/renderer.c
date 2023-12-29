/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:58:35 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 14:38:52 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "renderer.h"
#include "libft.h"
#include "math.h"

static t_buffer	*g_buffer;

uint32_t	r_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint32_t	c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	c = (c << 8) | a;
	return (c);
}

uint32_t	r_get_pixel(mlx_texture_t *texture, int x, int y)
{
	uint32_t	i;
	uint8_t		*pixel;

	i = (y * texture->width + x) * texture->bytes_per_pixel;
	pixel = &texture->pixels[i];
	return (r_color(pixel[0], pixel[1], pixel[2], pixel[3]));
}

void	r_init(void	*param)
{
	mlx_t		*mlx;
	mlx_image_t	*frame;

	g_buffer = malloc(sizeof(t_buffer));
	if (!g_buffer)
		return ;
	mlx = param;
	frame = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!frame)
		return ;
	mlx_image_to_window(mlx, frame, 0, 0);
	g_buffer->frame = frame;
}

t_buffer	*r_get_buffer(void)
{
	return (g_buffer);
}

void	r_clear(uint32_t color)
{
	size_t			i;
	uint8_t			*mem;
	size_t			x;

	x = 0;
	while (x < WIDTH)
		g_buffer->depth[x++] = INFINITY;
	i = 0;
	mem = g_buffer->frame->pixels;
	while (i < ((WIDTH * HEIGHT) * sizeof(uint32_t)))
	{
		mem[i++] = (uint8_t)(color >> 24);
		mem[i++] = (uint8_t)(color >> 16);
		mem[i++] = (uint8_t)(color >> 8);
		mem[i++] = (uint8_t)color;
	}
}
