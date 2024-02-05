/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/05 16:55:09 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <MLX42/MLX42.h>

bool		c_init(void *params);
void		c_keys(mlx_key_data_t keydata, void *params);
void		c_tick(void *params);
void		c_mouse(double xpos, double ypos, void* param);
void		c_exit(void* param);
void		c_set_exit(bool status);
bool*		c_get_exit(void);

#endif