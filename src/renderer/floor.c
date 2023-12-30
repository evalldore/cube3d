/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:42 by evallee-          #+#    #+#             */
/*   Updated: 2023/12/29 20:02:47 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"

static mlx_image_t	*g_floor;

void r_floor_draw()
{
	t_ivec	offset;
	t_ivec	coord;

	offset = (t_ivec){WIDTH / 2, HEIGHT / 4};
	coord = (t_ivec){0, 0};

}

void	r_floor_init(mlx_t *mlx)
{
	g_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);

	ft_memset(g_floor->pixels, 255, WIDTH * (HEIGHT / 2) * sizeof(uint32_t));

	mlx_image_to_window(mlx, g_floor, 0, HEIGHT / 2);
}
