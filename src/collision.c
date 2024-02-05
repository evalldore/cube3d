/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:00:04 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/04 23:27:52 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "utils.h"

t_ivec	collision_check(t_fvec pos, t_fvec dir)
{
	t_uvec	check;
	t_ivec	res;

	res = (t_ivec){0, 0};
	check.x = (uint32_t)(pos.x + dir.x * 0.5f);
	check.y = (uint32_t)pos.y;
	res.x = world_is_wall(check);
	check.x = (uint32_t)pos.x;
	check.y = (uint32_t)(pos.y + dir.y * 0.5f);
	res.y = world_is_wall(check);
	return (res);
}
