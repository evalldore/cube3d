/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/20 15:12:49 by aroussea         ###   ########.fr       */
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
	t_uvec	size;

	if (argc < 2)
		ft_error("Not enough arguments!\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
		ft_error("mlx failed to init!\n");
	mlx_set_cursor_mode(mlx, MLX_MOUSE_DISABLED);
	size = (t_uvec){mlx->width * SCALE, mlx->height * SCALE};
	mlx_set_window_size(mlx, size.x, size.y);
	mlx_set_window_pos(mlx, 2560 / 2 - (size.x / 2), 1440 / 2 - (size.y / 2));
	mlx_key_hook(mlx, c_keys, mlx);
	mlx_loop_hook(mlx, &c_tick, mlx);
	mlx_cursor_hook(mlx, &c_mouse, mlx);
	if (!c_init(mlx, argv[1]))
		return (c_exit(mlx, EXIT_FAILURE));
	mlx_loop(mlx);
	return (c_exit(mlx, EXIT_SUCCESS));
}
