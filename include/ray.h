/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:01:43 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/13 16:07:59 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <stdbool.h>
# include "vector.h"

typedef struct s_ray
{
	t_fvec		pos;
	t_fvec		dir;
	uint32_t	length;
	bool		(*check)(t_uvec);
}	t_ray;

typedef struct s_hit
{
	float	dist;
	t_uvec	coords;
	bool	collide;
	t_fvec	pos;
	t_ivec	norm;
}	t_hit;

t_hit	ray_cast(t_ray *r);

#endif