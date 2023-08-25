/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/08/23 20:18:37 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "cube.h"
#include "renderer.h"

// Exit the program as failure.
static void	ft_error(char *err)
{
	if (err)
		ft_printf(err);
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char	**argv)
{
	mlx_t	*mlx;

	(void)argc;
	(void)argv;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cube3D", true);
	if (!mlx)
		ft_error("mlx failed to init!\n");
	mlx_set_window_size(mlx, mlx->width * 2, mlx->height * 2);
	mlx_key_hook(mlx, c_keys, NULL);
	mlx_loop_hook(mlx, &c_tick, mlx);
	c_init(mlx);
	mlx_loop(mlx);
	c_exit();
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
