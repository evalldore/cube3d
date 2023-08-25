#ifndef	CAMERA_H
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