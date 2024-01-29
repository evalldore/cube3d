/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:58:17 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/28 23:18:56 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H 
# include <math.h>
# include <stdbool.h>
# include "utils.h"
# include "vector.h"
# include "world.h"

t_ivec	collision_check(t_fvec pos, t_fvec dir);

#endif 