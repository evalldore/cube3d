/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:45:19 by evallee-          #+#    #+#             */
/*   Updated: 2023/12/27 14:38:54 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# include "renderer.h"
# include "vector.h"
# include "assets.h"

typedef struct s_point
{
	t_fvec		uv;
	t_uvec		pos;
	uint32_t	color;
}	t_point;

void	r_draw_line(uint32_t x, uint32_t line[2], uint32_t len, uint32_t coordx);
void	r_set_asset(uint32_t index);

#endif