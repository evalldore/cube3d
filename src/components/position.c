/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:26:59 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 19:22:26 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	position_new(void *ptr, va_list args)
{
	t_comp_pos	*pos;

	pos = ptr;
	pos->curr.x = (float)va_arg(args, double);
	pos->curr.y = (float)va_arg(args, double);
	pos->last = pos->curr;
}

void	comp_pos_reg(void)
{
	ecs_comp_register(COMP_POS, sizeof(t_comp_pos), position_new, NULL);
}
