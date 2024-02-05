/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:01:49 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/05 02:31:41 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "math.h"
#include "utils.h"

static void	ray_init(t_ray *r, t_uvec *check, t_fvec *step, t_fvec *length)
{
	check->x = (uint32_t)r->pos.x;
	check->y = (uint32_t)r->pos.y;
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

static t_hit	ray_loop(t_ray *r, t_uvec check, t_fvec step, t_fvec length)
{
	t_hit		hit;
	uint32_t	i;

	i = 0;
	hit.dist = 0.0f;
	while (!r->check(check) && i++ <= r->length)
	{
		hit.norm = (t_ivec){0, 0};
		if (length.x < length.y) 
		{
			hit.norm.x = sign(r->dir.x);
			check.x += hit.norm.x;
			hit.dist = length.x;
			length.x += step.x;
			continue ;
		}
		hit.norm.y = sign(r->dir.y);
		check.y += hit.norm.y;
		hit.dist = length.y;
		length.y += step.y;
	}
	hit.collide = r->check(check);
	hit.coords = check;
	return (hit);
}

t_hit	ray_cast(t_ray *r)
{
	t_uvec	check;
	t_fvec	step;
	t_fvec	length;
	t_hit	result;

	ray_init(r, &check, &step, &length);
	result = ray_loop(r, check, step, length);
	result.pos.x = r->pos.x + r->dir.x * result.dist;
	result.pos.y = r->pos.y + r->dir.y * result.dist;
	return (result);
}
