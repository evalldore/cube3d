/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:58:35 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/25 23:27:31 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "renderer.h"
#include "libft.h"

static	mlx_image_t	*g_buffer;

uint32_t	r_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint32_t	c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	c = (c << 8) | a;
	return (c);
}

void	r_init(void	*param)
{
	mlx_t	*mlx;

	mlx = param;
	g_buffer = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!g_buffer)
		return ;
	mlx_image_to_window(mlx, g_buffer, 0, 0);
}

void	*r_get_buffer()
{
	return (g_buffer);
}

void	r_clear(uint32_t color)
{
	size_t			l;
	size_t			i;
	uint8_t			*mem;

	i = 0;
	l = (WIDTH * HEIGHT) * sizeof(uint32_t);
	mem = g_buffer->pixels;
	while (i < l)
	{
		mem[i++] = (uint8_t)(color >> 24);
		mem[i++] = (uint8_t)(color >> 16);
		mem[i++] = (uint8_t)(color >> 8);
		mem[i++] = (uint8_t)color;
	}
}
