/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:42:38 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/26 16:56:27 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

float	dist(float x1, float y1, float x2, float y2)
{
	float	dist_x;
	float	dist_y;

	dist_x = (x2 - x1);
	dist_y = (y2 - y1);
	return (sqrt((dist_x * dist_x) + (dist_y * dist_y)));
}

float	deg2rad(float a)
{
	return (a * M_PI / 180.0f);
}

float	rotate(float rad, float dist)
{
	rad = rad + dist;
	if (rad < 0.0f)
		rad += 2 * M_PI;
	else if (rad > 2 * M_PI)
		rad -= 2 * M_PI;
	return (rad);
}

int	sign(float value)
{
	if (value > 0.0f)
		return (1);
	else if (value < 0.0f)
		return (-1);
	return (0);
}

t_fvec	normalize(float x, float y)
{
	double	l;
	t_fvec	norm;

	norm.x = 0.0f;
	norm.y = 0.0f;
	l = sqrt((double)((x * x) + (y * y)));
	if (l != 0.0)
	{
		norm.x = x / l;
		norm.y = y / l;
	}
	return (norm);
}
