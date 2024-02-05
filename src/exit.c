/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:28 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/05 16:54:27 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool*   c_get_exit(void)
{
    static bool should_exit;

    return (&should_exit);
}

void    c_set_exit(bool status)
{
    bool    *should_exit;

    should_exit = c_get_exit();
    *should_exit = status;
}

void	c_exit(void* param)
{
    mlx_close_window(param);
}