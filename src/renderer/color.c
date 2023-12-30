/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:34:27 by evallee-          #+#    #+#             */
/*   Updated: 2023/12/29 16:52:32 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

uint32_t	*r_get_color(void)
{
	static uint32_t	r_color;

	return (&r_color);
}

void	r_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint8_t	*r_color;

	r_color = (uint8_t *)r_get_color();
	r_color[0] = r;
	r_color[1] = g;
	r_color[2] = b;
	r_color[3] = a;
}

uint32_t	r_calc_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
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
	return (r_calc_color(pixel[0], pixel[1], pixel[2], pixel[3]));
}