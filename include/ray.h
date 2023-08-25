#ifndef	RAY_H
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
	t_ivec	norm;
}	t_hit;

t_hit	ray_cast(t_ray *r);

#endif