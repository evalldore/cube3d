/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:58:35 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/13 15:42:24 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "renderer.h"
#include "libft.h"
#include "math.h"

void	r_init(void	*param)
{
	mlx_image_t	*frame;
	t_buffer	*buffer;

	buffer = r_get_buffer();
	r_back_init(param);
	r_floor_init(param);
	frame = mlx_new_image(param, WIDTH, HEIGHT);
	if (!frame)
		return ;
	mlx_image_to_window(param, frame, 0, 0);
	buffer->frame = frame;
}
