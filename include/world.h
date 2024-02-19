/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:08:19 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/13 16:08:26 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include <math.h>
# include <stdint.h>
# include <MLX42/MLX42.h>
# include "vector.h"
# include "camera.h"

typedef struct s_start
{
	t_fvec	coords;
	float	dir;
}	t_start;

typedef struct s_world
{
	t_uvec		size;
	t_start		start;
	uint32_t	colors[2];
	char		*assets[4];
	uint8_t		**data;

}	t_world;

void		world_draw(t_camera cam);
bool		world_is_wall(t_uvec check);
bool		world_init(mlx_t *mlx, char *path);
t_world		*world_get(void);

#endif