#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "vector.h"

void		world_draw();
bool		world_is_wall(t_uvec check);
void		world_init(void);

#endif