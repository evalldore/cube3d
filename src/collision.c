/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:00:04 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/04 23:26:09 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "utils.h"

t_ivec	collision_check(t_fvec pos, t_fvec dir)
{
	t_uvec	check;
	t_ivec	res;

	check.x = (uint32_t)(pos.x + dir.x * 0.5f);
	check.y = (uint32_t)pos.y;
	res = (t_ivec){0, 0};
	if (world_is_wall(check))
		res.x = 1;
	check.x = (uint32_t)pos.x;
	check.y = (uint32_t)(pos.y + dir.y * 0.5f);
	if (world_is_wall(check))
		res.y = 1;
	return (res);
}
