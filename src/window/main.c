/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/17 23:31:03 by phwang           ###   ########.fr       */
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
	mlx_key_hook(window.win_ptr, &handle_input_key, &window);
	mlx_hook(window.win_ptr, 17, 0, &handle_mouse_esc, &window);
	mlx_loop(window.mlx_ptr);
	ft_destroy(window);
}
