/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/22 18:02:36 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

void	r_draw_line(t_uvec start, uint32_t len, uint32_t color)
{
	uint32_t	y;
	t_buffer	*buffer;

	y = start.y;
	buffer = r_get_buffer();
	while (y < len)
		mlx_put_pixel(buffer->frame, start.x, y++, color);
}
