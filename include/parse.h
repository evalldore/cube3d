/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:02 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/20 15:40:53 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <unistd.h>
#include "world.h"
#include "libft.h"
#include "renderer.h"
#include <fcntl.h>

int	check_path(char *path);
int assign_texture(char *str);
int	ft_strcmpbyend(char *s1, char *s2);
int check_color(char *str);
int extract_map(char *str, int fd);
int start_pos(char **map);
int free_map(char **map, int return_val, size_t y);

#endif