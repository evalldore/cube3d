/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:01:49 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 19:21:14 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "math.h"
#include "utils.h"

static void	ray_init(t_ray *r, t_uvec *check, t_fvec *step, t_fvec *length)
{
	check->x = (int)r->pos.x;
	check->y = (int)r->pos.y;
	step->x = INFINITY;
	step->y = INFINITY;
	if (r->dir.x != 0.0f)
		step->x = fabs(1.0f / r->dir.x);
	if (r->dir.y != 0.0f)
		step->y = fabs(1.0f / r->dir.y);
	length->x = ((float)(check->x + 1) - r->pos.x) * step->x;
	length->y = ((float)(check->y + 1) - r->pos.y) * step->y;
	if (r->dir.x < 0) 
		length->x = (r->pos.x - (float)check->x) * step->x;
	if (r->dir.y < 0) 
		length->y = (r->pos.y - (float)check->y) * step->y;
}

static float	ray_loop(t_ray *r, t_uvec *check, t_fvec *step, t_fvec *length)
{
	float		distance;
	uint32_t	i;

	i = 0;
	distance = 0.0f;
	while (!r->check(*check) && i <= r->length)
	{
		if (length->x < length->y) 
		{
			check->x += sign(r->dir.x);
			distance = length->x;
			length->x += step->x;
		} 
		else 
		{
			check->y += sign(r->dir.y);
			distance = length->y;
			length->y += step->y;
		}
		i++;
	}
	return (distance);
}

float	ray_cast(t_ray *r)
{
	t_uvec	check;
	t_fvec	step;
	t_fvec	length;
	float	distance;
	
	ray_init(r, &check, &step, &length);
	distance = ray_loop(r, &check, &step, &length);
	return (distance);
}
