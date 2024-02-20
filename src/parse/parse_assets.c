/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:51:26 by aroussea          #+#    #+#             */
/*   Updated: 2024/02/20 15:55:09 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int check_prefix_dir(char *str)
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
