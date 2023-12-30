/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:26:59 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 19:22:45 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	control_new(void *ptr, va_list args)
{
	t_comp_ctrl	*ctrl;

	(void)args;
	ctrl = ptr;
	ctrl->up = false;
	ctrl->down = false;
	ctrl->left = false;
	ctrl->right = false;
}

void	comp_ctrl_reg(void)
{
	ecs_comp_register(COMP_CTRL, sizeof(t_comp_ctrl), control_new, NULL);
}
