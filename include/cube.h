/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/16 21:45:43 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <MLX42/MLX42.h>

bool		c_init(void *params);
void		c_keys(mlx_key_data_t keydata, void *params);
void		c_tick(void *params);
void		c_mouse(double xpos, double ypos, void* param);
void		c_exit(void);

#endif