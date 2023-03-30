/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:33:14 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/30 15:56:42 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECS_H
# define ECS_H
# define MAX_ENTS 256
# define MAX_COMP 32
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

typedef void *(*t_constructor)(va_list);
typedef void (*t_destructor)(void	*);
typedef void (*t_system)(uint32_t, va_list);

typedef struct s_component
{
	t_constructor	new;
	t_destructor	dest;
	void			*ptrs[MAX_ENTS];
}	t_component;

uint32_t	ecs_create(void);
uint32_t	ecs_num(void);
void		ecs_remove(uint32_t	ent_id);
void		*ecs_comp_add(uint32_t ent_id, int comp, int argc, ...);
void		ecs_comp_remove(uint32_t ent_id, int comp);
void		ecs_comp_register(int comp, t_constructor c, t_destructor d);
void		*ecs_comp_get(uint32_t ent_id, int comp);
void		ecs_iterate(void (*f)(uint32_t, va_list), ...);

#endif