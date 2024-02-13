/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/13 16:06:16 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <MLX42/MLX42.h>

bool		c_init(mlx_t *mlx, char *path);
void		c_keys(mlx_key_data_t keydata, void *params);
void		c_tick(void *params);
void		c_mouse(double xpos, double ypos, void *param);
void		c_exit(void);

#endif