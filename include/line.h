/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:45:19 by evallee-          #+#    #+#             */
/*   Updated: 2023/11/22 17:50:38 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# include "renderer.h"
# include "vector.h"

typedef struct s_point
{
	t_fvec		tex;
	t_uvec		pos;
	uint32_t	color;
}	t_point;

void	r_draw_line(t_uvec start, uint32_t len, uint32_t color);

#endif