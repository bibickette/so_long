/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 01:26:18 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_win	window;
	
	// map_check(argv[1], window);
	if (create_window(&window, "Very very long") == ERROR)
		return (ERROR);
	mlx_key_hook(window.win_ptr, &esc_exit, &window);
	mlx_hook(window.win_ptr, 17, 0, &cross_exit, &window);
	mlx_loop(window.mlx_ptr);
	ft_destroy(&window);
}
