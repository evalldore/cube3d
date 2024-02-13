/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:22:21 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/13 16:07:33 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include <stdint.h>
# include <MLX42/MLX42.h>
# include "vector.h"
# include "assets.h"
# include "camera.h"
# define WIDTH 800
# define HEIGHT 600
# define DRAW_DISTANCE 24
# define SCALE 2

typedef struct s_buffer
{
	mlx_image_t	*frame;
	float		depth[WIDTH];
}	t_buffer;

typedef struct s_point
{
	t_fvec		uv;
	t_uvec		pos;
	uint32_t	color;
}	t_point;

void		r_init(void	*param);
void		r_clear(uint32_t color);
uint32_t	r_calc_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
uint32_t	*r_get_color(void);
void		r_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
uint32_t	r_get_pixel(mlx_texture_t *texture, int x, int y);
t_buffer	*r_get_buffer(void);
void		r_draw_line(uint32_t x, int line[], uint32_t len, uint32_t coordx);
void		r_back_init(mlx_t	*mlx);
void		r_set_asset(uint32_t index);
void		r_floor_init(mlx_t *mlx);
void		r_floor_draw(t_camera ang);

#endif