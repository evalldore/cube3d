/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/21 15:05:28 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <MLX42/MLX42.h>
# include "vector.h"
# ifndef BONUS
#  define BONUS 0
# endif

bool		c_init(mlx_t *mlx, char *path);
void		c_keys(mlx_key_data_t keydata, void *params);
void		c_tick(void *params);
void		c_mouse(double xpos, double ypos, void *param);
int			c_exit(mlx_t *mlx, int return_val);

void		controls_tick(mlx_t *mlx);
void		controls_mouse(t_fvec move);
void		controls_keys(mlx_key_data_t keydata, void *param);

#endif