/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:00:04 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/26 15:44:25 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "utils.h"

t_ivec	collision_check(t_fvec pos, t_fvec dir)
{
	t_uvec	check;

	check.x = (uint32_t)(pos.x + dir.x * 0.5f);
	check.y = (uint32_t)pos.y;
	if (world_is_wall(check))
		return ((t_ivec){1, 0});
	check.x = (uint32_t)pos.x;
	check.y = (uint32_t)(pos.y + dir.y * 0.5f);
	if (world_is_wall(check))
		return ((t_ivec){0, 1});
	return ((t_ivec){0, 0});
}
