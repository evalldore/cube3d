/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:58:35 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/25 00:17:20 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "renderer.h"

static	mlx_image_t *g_buffer;

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

void	r_clear()
{
	uint32_t	i;

	i = 0;
	while (i < (WIDTH * HEIGHT))
	{
		g_buffer->pixels[i] = 0;
		i++;
	}
}
