/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:09:37 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:29 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	ft_strcmpbyend(char *s1, char *s2)
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

static int distribution(char *str, int fd)
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

static int parsing(int fd)
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
