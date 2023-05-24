/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:47:27 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/24 00:30:56 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	anim_new(void *ptr, va_list args)
{
	t_c_anim	*anim;

	anim = ptr;
	anim->index = va_arg(args, int32_t);
	anim->frame = 0;
	anim->time = 0.0;
}

void	comp_anim_reg(void)
{
	size_t	size;

	size = sizeof(t_c_anim);
	ecs_comp_register(COMP_ANIM, size, &anim_new, NULL);
}
