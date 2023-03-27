/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:55:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 19:14:17 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	sys_movement(double dt)
{
	comp_pos_t	*pos;
	comp_vel_t	*vel;
	ent_id_t	ent;

	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		vel = ecs_comp_get(ent, COMP_VEL);
		if (pos && vel)
		{
			pos->curr.x += vel->curr.x * dt;
			pos->curr.y += vel->curr.y * dt;
			if (pos->curr.y < 0)
				pos->curr.y = 0;
			if (pos->curr.y > 512)
			{
				pos->curr.y = 512;
				vel->curr.y = 0;
			}
		}
		ent++;
	}
}
