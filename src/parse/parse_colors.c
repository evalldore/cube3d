/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:56:53 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/21 14:04:11 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	assign_color(long *color, int f)
{
	t_world	*world;
	int		i;

	i = 0;
	world = world_get();
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (-1);
		i++;
	}
	if (f == 1 && (u_int8_t)world->colors[0] == 0)
		world->colors[0] = r_calc_color((uint8_t)color[0],
				(uint8_t)color[1], (uint8_t)color[2], 255);
	else if ((u_int8_t)world->colors[1] == 0)
		world->colors[1] = r_calc_color((uint8_t)color[0],
				(uint8_t)color[1], (uint8_t)color[2], 255);
	else
		return (-1);
	return (0);
}

static int	color_valid(char *str)
{
	str++;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '-'
			&& *str != ',' && *str != '\n' && !ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	extract_color(char *str, int f)
{
	int		util[3];
	char	*sub;
	long	colors[3];

	util[0] = 0;
	util[1] = 0;
	if (color_valid(str))
		return (free (str), -1);
	while ((size_t)util[0] < ft_strlen(str) && util[1] != 3)
	{
		if (ft_isdigit(str[util[0]]) || str[util[0]] == '-')
		{
			util[2] = ft_strchr(&str[util[0]], ',') - (&str[util[0]]);
			sub = ft_substr(str, (&str[util[0]] - str), util[2]);
			colors[util[1]++] = ft_atoi(sub);
			util[0] += util[2];
			free (sub);
		}
		else
			util[0]++;
	}
	if ((size_t)util[0] < ft_strlen(str))
		return (free (str), -1);
	return (free (str), assign_color(colors, f));
}

static int	check_prefix_col(char *str)
{
	static char	*poss_pre_dir[] = {"F ", "C "};
	char		*sub;
	int			i;

	i = 0;
	if (str[1] == ' ')
	{
		sub = ft_substr(str, 0, 2);
		while (i < 2)
		{
			if (!ft_strcmpbyend(sub, poss_pre_dir[i]))
			{
				free (sub);
				return (i);
			}
			i++;
		}
		free (sub);
	}
	return (-1);
}

int	check_color(char *str)
{
	int	res;

	res = check_prefix_col(str);
	if (res == -1)
	{
		free (str);
		return (-1);
	}
	if (res == 0)
		return (extract_color(str, 1));
	else
		return (extract_color(str, 0));
}
