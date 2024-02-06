/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/06 17:50:53 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "cube.h"
#include "renderer.h"

// Exit the program as failure.
static void	ft_error(const char *err)
{
	if (err)
		write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char	**argv)
{
	mlx_t	*mlx;

	if (argc < 2)
		ft_error("Not enough arguments!\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cube3D", true);
	if (!mlx)
		ft_error("mlx failed to init!\n");
	mlx_set_cursor_mode(mlx, MLX_MOUSE_DISABLED);
	mlx_set_window_size(mlx, mlx->width * SCALE, mlx->height * SCALE);
	mlx_key_hook(mlx, c_keys, mlx);
	mlx_loop_hook(mlx, &c_tick, mlx);
	mlx_cursor_hook(mlx, &c_mouse, mlx);
	if (!c_init(mlx, argv[1]))
	{
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	c_exit();
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
