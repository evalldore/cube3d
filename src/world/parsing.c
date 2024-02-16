/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:09:37 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/16 16:13:07 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "world.h"
#include "libft.h"
#include "renderer.h"
#include <fcntl.h>

static int	ft_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

static int	ft_strcmpbyend(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *(s1 + 1))
		s1++;
	while (*s2 && *(s2 + 1) && s2++)
		i++;
	while (i >= 0)
	{
		if (*s1 != *s2)
			return (1);
		--s1;
		--s2;
		i--;
	}
	return (0);
}

int check_prefix_dir(char *str)
{
	char *poss_pre_dir[] = {"NO ", "SO ", "WE ", "EA "};
	char *sub;
	int i;
	
	i = 0;
	if (str[2] == ' ')
	{
		sub = ft_substr(str, 0, 3);
		while (i < 4)
		{
			if (!ft_strcmpbyend(sub, poss_pre_dir[i]))
				return (i);
			i++;
		}
		free(sub);
	}
	return (-1);
}

int check_prefix_col(char *str)
{
	char *poss_pre_dir[] = {"F ", "C "};
	char *sub;
	int i;
	
	i = 0;
	if (str[1] == ' ')
	{
		sub = ft_substr(str, 0, 2);
		while (i < 2)
		{
			if (!ft_strcmpbyend(sub, poss_pre_dir[i]))
				return (i);
			i++;
		}
		free(sub);
	}
	return (-1);
}

int assign_color(long *color, int f)
{
	int i;
	t_world *world;

	i = 0;
	world = world_get();
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (-1);
		i++;
	}
	if (f == 1)
		world->colors[0] = r_calc_color((uint8_t)color[0], (uint8_t)color[1], (uint8_t)color[2], 255);
	else
		world->colors[1] = r_calc_color((uint8_t)color[0], (uint8_t)color[1], (uint8_t)color[2], 255);
	return (0);
}

int extract_color(char *str, int f)
{
	int i;
	int j;
	int len;
	char *sub;
	long colors[3];

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			len = ft_strchr(&str[i], ',') - (&str[i]);
			sub = ft_substr(str, (&str[i] - str), len);
			colors[j++] = ft_atoi(sub);
			i += len;
			free(sub);
		} else
			i++;
		if (j == 3)
			break;
	}
	return (assign_color(colors, f));
}

int check_color(char *str)
{
	int res;

	res = check_prefix_col(str);
	if (res == -1)
		return (-1);
	if (res == 0)
		return (extract_color(str, 1));
	else
		return (extract_color(str, 0));
}

int assign_texture(char *str)
{	
	t_world *world;
	int res;

	world = world_get();
	res = check_prefix_dir(str);
	if (res == -1)
		return (-1);
	world->assets[res] = ft_substr(str, 3, ft_strlen(str) - 4);
	free(str);
	return (0);
}

int transfer_map(char **map_tmp, int rows, int cols)
{
	char **map;
	int i;
	int j;
	
	map = (char **)ft_calloc(rows, sizeof(char *));
	i = 0;
	while (i < rows)
	{
		map[i] = (char *)ft_calloc((cols + 1), sizeof(char));
		j = 0;
		while (j < cols)
		{
			if (map_tmp[i] && map_tmp[i][j] != '\0')
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
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}

int split_map(char *buffer)
{
	char **map;
	int i;
	int j;
	int size;

	map = ft_split(buffer, '\n');
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
	return (transfer_map(map, i, size));
} 

int check_map_char(char *str)
{
	while (*str)
	{
		if (*str == '1' || *str == '0' || *str == 'N' || *str == 'S' || *str == 'E' ||
			 *str == 'W' || *str == ' ' || *str == '\t' || *str == '\n')
			str++;
		else
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
			return (1);
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

int distribution(char *str, int fd)
{
	if (ft_isalpha(str[0]) && str[2] == ' ')
		return (assign_texture(str));
	else if (ft_isalpha(str[0]) && str[1] == ' ')
		return (check_color(str));
	else if (str[0] == '\n')
		return (0);
	else
		return (extract_map(str, fd));
	return (0);
}

int parsing(int fd)
{
	char *str;

	while (true)
	{
		str = ft_get_next_line(fd);
		if (str == NULL)
			break;
		if (distribution(str, fd) == -1)
			return (1);
	}
	return (0);
}

int	check_path(char *path)
{
	int fd;

	if (ft_strcmpbyend(path, ".cub"))
		return (ft_err("Error\nThe file isn't a .cub file.\n"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_err("Error\nCannot open the file.\n"));
	if (parsing(fd))
		return (ft_err("Error\nParsing.\n"));
	close(fd);
	return (0);
}
