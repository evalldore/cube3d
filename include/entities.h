/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:46:28 by niceguy           #+#    #+#             */
/*   Updated: 2024/01/16 22:03:53 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H
# include <ecs.h>
# include <MLX42/MLX42.h>
# include "vector.h"
# include "stdbool.h"

enum e_comp
{
	COMP_POS,
	COMP_CTRL,
	COMP_DIR
};

typedef struct s_comp_pos
{
	t_fvec	curr;
	t_fvec	last;
}	t_comp_pos;

typedef struct c_comp_ctrl
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_comp_ctrl;

typedef struct c_comp_dir
{
	float	curr;
	float	last;
}	t_comp_dir;

void		ents_init(void);
uint32_t	ents_player(t_fvec pos, float dir);

void		comp_pos_reg(void);
void		comp_ctrl_reg(void);
void		comp_dir_reg(void);

void		sys_controls(uint32_t ent, va_list args);
void		sys_controls_keys(mlx_key_data_t keydata, void *param);
void		sys_controls_mouse(t_fvec move);


#endif