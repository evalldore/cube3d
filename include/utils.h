/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:31:47 by evallee-          #+#    #+#             */
/*   Updated: 2024/01/26 16:54:54 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "vector.h"

float		rotate(float rad, float dist);
float		deg2rad(float a);
float		dist(float x1, float y1, float x2, float y2);
int			sign(float value);
t_fvec		normalize(float x, float y);
#endif