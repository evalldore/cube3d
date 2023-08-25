/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:33:38 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 20:46:49 by niceguy          ###   ########.fr       */
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
	float		planeAngle;

	planeAngle = rotate(cam.angle, deg2rad(90.f));
	plane.x = cos(planeAngle);
	plane.y = sin(planeAngle);
	return (plane);
}