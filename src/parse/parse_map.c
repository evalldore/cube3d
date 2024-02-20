/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:13 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:29 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int transfer_map(char **map_tmp, size_t rows, size_t cols)
{
	char **map;
	size_t i;
	size_t j;
	
	map = (char **)ft_calloc(rows, sizeof(char *));
	if (map == NULL)
		return (1);
	i = 0;
	while (i < rows)
	{
		map[i] = (char *)ft_calloc((cols + 1), sizeof(char));
		if (map[i] == NULL)
			return (1);
		j = 0;
		while (j < cols)
		{
			if (j < ft_strlen(map_tmp[i]))
			{
				if (map_tmp[i][j] == ' ' || map_tmp[i][j] == '\t')
					map[i][j] = 'x';
				else 
					map[i][j] = map_tmp[i][j];
			} else
				map[i][j] = 'x';
			j++;
		}
		map[i][j] = '\0'; 
		i++;
	}
	free_map(map_tmp, 0, rows);
	return (start_pos(map));
}

static int split_map(char *buffer)
{
	t_world *world;
	char **map;
	int i;
	int j;
	int size;

	map = ft_split(buffer, '\n');
	world = world_get();
	free(buffer);
	i = 0;
	size = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
		if (j > size)
			size = j;
	}
	world->size.x = size;
	world->size.y = i;
	return (transfer_map(map, i, size));
} 

static int check_map_char(char *str)
{
	static int player_start;
	
	if (*str == '\n')
		return (1);
	while (*str)
	{
		if (*str == '1' || *str == '0' || *str == ' ' || *str == '\t' || *str == '\n')
			str++;
		else if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
		{
			if (player_start >= 1)
				return (1);
			else
				player_start++;
			str++;
		} else
			return (1);
	}
	return (0);
}

int extract_map(char *str, int fd)
{
	char *buffer;
	char *check;
	char *tmp;
	
	buffer = str;
	check = ft_get_next_line(fd);
	if (check_map_char(buffer) == 1)
			return (-1);
	while (check != NULL)
	{
		if (check_map_char(check) == 1)
			return (-1);
		tmp = ft_strjoin(buffer, check);
		free(buffer);
		free(check);
		buffer = tmp;
		check = ft_get_next_line(fd);
	}
	if (split_map(buffer) == 1)
		return (-1);
	return (0);
}
