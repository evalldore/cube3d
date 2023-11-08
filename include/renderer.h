/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:22:21 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/08 15:23:44 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# include <stdint.h>
# define RENDERER_H
# define WIDTH 800
# define HEIGHT 600

void		r_init(void	*param);
void		r_clear(uint32_t color);
uint32_t	r_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void		*r_get_buffer(void);

#endif