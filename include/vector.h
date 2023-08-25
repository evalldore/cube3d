/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:14:42 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/24 18:50:24 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdint.h>

typedef struct s_ivector
{
	int32_t		x;
	int32_t		y;
}	t_ivec;

typedef struct s_uvector
{
	uint32_t	x;
	uint32_t	y;
}	t_uvec;

typedef struct s_dvector
{
	double	x;
	double	y;
}	t_dvec;

typedef struct s_fvector
{
	float	x;
	float	y;
}	t_fvec;

#endif