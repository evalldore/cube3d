/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:47:33 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/02 01:57:32 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static uint32_t	g_entities;

uint32_t	ecs_num(void)
{
	return (g_entities);
}

uint32_t	ecs_create(void)
{
	if (g_entities >= MAX_ENTS)
		return (-1);
	return (g_entities++);
}

void	ecs_remove(uint32_t ent_id)
{
	int32_t	comp;

	if (ent_id >= g_entities)
		return ;
	comp = 0;
	while (comp < MAX_COMP)
		ecs_comp_remove(ent_id, comp++);
}

void	ecs_clear(void)
{
	uint32_t	ent_id;

	ent_id = 0;
	while (ent_id < g_entities)
		ecs_remove(ent_id++);
}

void	ecs_iterate(t_system f, ...)
{
	uint32_t	ent_id;
	va_list		o_args;
	va_list		e_args;

	if (!f)
		return ;
	ent_id = 0;
	va_start(o_args, f);
	while (ent_id < g_entities)
	{
		va_copy(e_args, o_args);
		f(ent_id++, e_args);
	}
	va_end(o_args);
	va_end(e_args);
}
