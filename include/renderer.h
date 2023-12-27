/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:22:21 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/23 17:29:17 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# include <stdint.h>
# include <MLX42/MLX42.h>
# define RENDERER_H
# define WIDTH 800
# define HEIGHT 600

typedef struct s_buffer
{
	mlx_image_t	*frame;
	float		depth[WIDTH];
}	t_buffer;

void		r_init(void	*param);
void		r_clear(uint32_t color);
uint32_t	r_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_buffer	*r_get_buffer(void);

#endif