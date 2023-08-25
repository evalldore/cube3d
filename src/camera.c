/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:33:38 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/25 13:55:49 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "math.h"
#include "utils.h"

t_fvec	camera_get_direction(t_camera cam)
{
	t_fvec	vec;

	vec.x = cos(cam.angle);
	vec.y = sin(cam.angle);
	return (vec);
}

t_fvec	camera_get_plane(t_camera cam)
{
	t_fvec		plane;
	float		plane_dir;

	plane_dir = rotate(cam.angle, deg2rad(90.f));
	plane.x = cos(plane_dir);
	plane.y = sin(plane_dir);
	return (plane);
}