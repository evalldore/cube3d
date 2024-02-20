/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:00:52 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/20 17:16:18 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

uint32_t	ents_player(t_fvec pos, float dir)
{
	uint32_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, pos.x + 0.5f, pos.y + 0.5f);
	ecs_comp_add(ent, COMP_DIR, 1, dir);
	ecs_comp_add(ent, COMP_CTRL, 1);
	return (ent);
}

void	ents_init(void)
{
	comp_ctrl_reg();
	comp_dir_reg();
	comp_pos_reg();
}
