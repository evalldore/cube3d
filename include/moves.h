/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 05:42:11 by evallee-          #+#    #+#             */
/*   Updated: 2023/04/06 05:54:20 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
# include <MLX42/MLX42.h>
# include <libft.h>

void	moves_add(void *parms);
void	moves_init(void *parms);
void	moves_update(void *parms);
void	moves_clear(void *param);

#endif