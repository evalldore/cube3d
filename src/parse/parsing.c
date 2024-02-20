/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:09:37 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/20 18:04:33 by aroussea         ###   ########.fr       */
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

static char *cut_spaces(char *str)
{
	char *sub;
	int i;
	
	i = 0;
	if (str[i] != ' ' && str[i] != '\t')
		return (str);
	while (str[i] == ' ' || str[i] == '\t')
	{
		if (ft_isdigit(str[i + 1]))
			return (str);
		else if (str[i + 1] == '\n')
		{
			free(str);
			return (NULL);
		}
		i++;
	}
	sub = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	return (sub);
}

static int distribution(char *str, int fd)
{
	str = cut_spaces(str);
	if (str == NULL)
		return (-1);
	else if (str[0] == '\n')
		return (0);
	else if (ft_isalpha(str[0]) && str[2] == ' ')
		return (assign_texture(str));
	else if (ft_isalpha(str[0]) && str[1] == ' ')
		return (check_color(str));
	return (extract_map(str, fd));
}

static int parsing(int fd)
{
	char *str;

	while (true)
	{
		str = ft_get_next_line(fd);
		if (str == NULL)
			break;
		if (str[0] == '\n' && !str[1])
		{
			free(str);
			continue;
		}
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
