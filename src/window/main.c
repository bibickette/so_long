/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/17 23:37:47 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(void)
{
	t_win	window;

	window = create_window(500, 500, "Very very long by Bickette");
	if (!window.mlx_ptr || !window.win_ptr)
	{
		if (window.mlx_ptr)
			ft_destroy(window);
		ft_printf("%s", ERROR_MSG);
		exit (-1);
	}
	mlx_key_hook(window.win_ptr, &esc_exit, &window);
	mlx_hook(window.win_ptr, 17, 0, &cross_exit, &window);
	mlx_loop(window.mlx_ptr);
	ft_destroy(window);
}
