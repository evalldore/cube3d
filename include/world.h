#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "vector.h"
# include "camera.h"

void		world_draw(t_camera cam);
bool		world_is_wall(t_uvec check);
void		world_init(void);

#endif