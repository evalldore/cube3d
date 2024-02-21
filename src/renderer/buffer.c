/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:34:59 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:21:11 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "renderer.h"

t_buffer	*r_get_buffer(void)
{
	static t_buffer	buffer;

	return (&buffer);
}

void	r_clear(uint32_t color)
{
	size_t			i;
	uint8_t			*mem;
	size_t			x;
	t_buffer		*buffer;

	buffer = r_get_buffer();
	x = 0;
	while (x < WIDTH)
		buffer->depth[x++] = INFINITY;
	i = 0;
	mem = buffer->frame->pixels;
	while (i < ((WIDTH * HEIGHT) * sizeof(uint32_t)))
	{
		mem[i++] = (uint8_t)(color >> 24);
		mem[i++] = (uint8_t)(color >> 16);
		mem[i++] = (uint8_t)(color >> 8);
		mem[i++] = (uint8_t)color;
	}
}
