/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 18:41:47 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void put_img_p(t_img which, t_img *whatimg, int where_x, int where_y)
{
	unsigned int 	color;
	char 			*pixel;
	int 			x;
	int 			y;

	y = -1;
	while (++y < IMG_HEIGHT)
	{
		x = -1;
		while (++x < IMG_WIDTH)
		{
			color = *(unsigned int *)(whatimg->addr + ((y * whatimg->line_len 
					+ x * ((whatimg->bpp / 8)))));
			pixel = which.addr + ((y + where_y * IMG_HEIGHT)
					* which.line_len + (x + where_x * IMG_WIDTH)
					* (which.bpp / 8));
			// if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
		}
	}
}

int	main(int argc, char **argv)
{
	t_long	so_long;

	set_map(argc, argv, &so_long);
	if (create_window(&so_long, "The Legend of SoLong") == ERROR)
		apocalypse(&so_long);
	// so_long.temp.mlx_img = 0;
	// so_long.temp.mlx_img = mlx_new_image(so_long.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	// so_long.temp.mlx_img = mlx_get_data_addr(so_long.temp.mlx_img, &(so_long.temp.bpp), &(so_long.temp.line_len), &(so_long.temp.endian));
	// put_img_p(so_long.temp, search_img(&so_long, P_UP), 0, 0);
	display(&so_long);
	// mlx_put_image_to_window(so_long.mlx_ptr, so_long.win_ptr, so_long.temp.mlx_img, so_long.player_x, so_long.player_y);
	mlx_key_hook(so_long.win_ptr, &handle_key, &so_long);
	mlx_hook(so_long.win_ptr, 17, 0, &cross_exit, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, &display, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
