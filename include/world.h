#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "vector.h"
# include "camera.h"

typedef struct s_start {
	t_uvec	coords;
	float	dir;
}	t_start;

typedef struct s_world {
	t_uvec		size;
	t_start		start;
	uint32_t	colors[2];
	int			assets[4];
	uint8_t		*data;

}	t_worls;

void		world_draw(t_camera cam);
bool		world_is_wall(t_uvec check);
void		world_init(void);

#endif