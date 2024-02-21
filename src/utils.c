/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:42:38 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/21 13:46:19 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include "utils.h"

int	ft_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

float	dist(float x1, float y1, float x2, float y2)
{
	t_fvec	dist;

	dist = (t_fvec){x2 - x1, y2 - y1};
	return (sqrt((dist.x * dist.x) + (dist.y * dist.y)));
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
