/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:30 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/13 16:05:42 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct s_camera
{
	t_fvec	pos;
	float	angle;
}	t_camera;

t_fvec	camera_get_direction(t_camera cam);
t_fvec	camera_get_plane(t_camera cam);

#endif