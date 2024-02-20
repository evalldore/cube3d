/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:56:53 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/20 15:55:31 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int assign_color(long *color, int f)
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

static int extract_color(char *str, int f)
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
	free(str);
	return (assign_color(colors, f));
}

static int check_prefix_col(char *str)
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
			{
				free(sub);
				return (i);
			}
			i++;
		}
		free(sub);
	}
	return (-1);
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
