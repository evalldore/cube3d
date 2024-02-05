/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:22:32 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/04 23:24:13 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_fvec fvec_normalize(t_fvec vec)
{
	double	l;
	t_fvec	norm;

	norm = (t_fvec){0.0f, 0.0f};
	l = sqrt((double)((vec.x * vec.x) + (vec.y * vec.y)));
	if (l != 0.0)
	{
		norm.x = vec.x / l;
		norm.y = vec.y / l;
	}
	return (norm);
}