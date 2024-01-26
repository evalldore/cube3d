/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:58:17 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/26 15:44:38 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H 
# include <math.h>
# include <stdbool.h>
# include "util.h"
# include "vector.h"
# include "world.h"

t_ivec	collision_check(t_fvec pos, t_fvec dir);

#endif 