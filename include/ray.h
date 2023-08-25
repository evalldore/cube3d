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
	t_fvec	norm;
}	t_hit;

float	ray_cast(t_ray *r);

#endif