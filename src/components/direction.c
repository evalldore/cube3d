/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:38:42 by niceguy           #+#    #+#             */
/*   Updated: 2023/12/29 19:22:22 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	direction_new(void	*ptr, va_list args)
{
	t_comp_dir	*dir;

	dir = ptr;
	dir->curr = (float)va_arg(args, double);
	dir->last = dir->curr;
}

void	comp_dir_reg(void)
{
	ecs_comp_register(COMP_DIR, sizeof(t_comp_dir), direction_new, NULL);
}
