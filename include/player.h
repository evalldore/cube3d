/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:39:52 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/21 15:03:47 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdbool.h>
# include "vector.h"

typedef struct s_ctrl
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	turn_left;
	bool	turn_right;
}	t_control;

typedef struct s_ply
{
	t_fvec		pos;
	float		dir;
	t_control	ctrl;
}	t_player;

t_player		*player_get(void);

#endif