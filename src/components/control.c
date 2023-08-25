/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:26:59 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 20:44:13 by niceguy          ###   ########.fr       */
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

void	comp_ctrl_reg()
{
	ecs_comp_register(COMP_CTRL, sizeof(t_comp_ctrl), control_new, NULL);
}
