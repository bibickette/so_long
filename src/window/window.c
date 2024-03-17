/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:20:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/17 00:36:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_destroy(t_win window)
{
	mlx_destroy_window(window.mlx_ptr, window.win_ptr);
	mlx_destroy_display(window.mlx_ptr);
	free(window.mlx_ptr);
}

t_win	create_window(int height, int width, char *str)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	return((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}
