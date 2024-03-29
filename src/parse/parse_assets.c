/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:51:26 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/21 13:26:19 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_prefix_dir(char *str)
{
	static char	*poss_pre_dir[4] = {"NO ", "SO ", "WE ", "EA "};
	char		*sub;
	int			i;

	i = 0;
	if (str[2] == ' ')
	{
		sub = ft_substr(str, 0, 3);
		while (i < 4)
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

int	assign_texture(char *str)
{
	t_world	*world;
	int		res;

	world = world_get();
	res = check_prefix_dir(str);
	if (res == -1)
		return (-1);
	if (world->assets[res] == NULL)
		world->assets[res] = ft_substr(str, 3, ft_strlen(str) - 4);
	else
		return (free (str), -1);
	free (str);
	return (0);
}
