#ifndef RENDERER_H
# define RENDERER_H
# define WIDTH 800
# define HEIGHT 600

void		r_init(void	*param);
void		r_clear(uint32_t color);
uint32_t	r_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void		*r_get_buffer();

#endif