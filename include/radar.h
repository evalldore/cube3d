/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:29:19 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:17:01 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADAR_H
# define RADAR_H
# include <MLX42/MLX42.h>
# include "world.h"
# include "vector.h"
# include "renderer.h"
# include "libft.h"
# define UNIT_SIZE 4

void	radar_init(mlx_t *mlx);
void	radar_draw(t_world *world, t_fvec pos);

#endif