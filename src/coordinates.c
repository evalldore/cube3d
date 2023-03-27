/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:32:47 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 01:49:24 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_uvector	pos_to_coords(double x, double y)
{
	t_uvector	coord;

	coord.x = (uint32_t)round((x + (TILE_SIZE / 2)) / TILE_SIZE) - 1;
	coord.y = (uint32_t)round((y + (TILE_SIZE / 2)) / TILE_SIZE);
	return (coord);
}