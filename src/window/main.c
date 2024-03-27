/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 20:09:35 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_long	so_long;

	set_map(argc, argv, &so_long);
	if (create_window(&so_long, "The Legend of SoLong") == ERROR)
		apocalypse(&so_long);
	mlx_key_hook(so_long.win_ptr, &handle_key, &so_long);
	mlx_hook(so_long.win_ptr, 17, 0, &cross_exit, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, &display, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
