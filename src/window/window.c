/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:20:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 01:34:21 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_destroy(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
}

int	create_window(t_win *window, char *str)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (ERROR);
	window->win_ptr = mlx_new_window(window->mlx_ptr, 64, 64, str);
	if (!window->win_ptr)
	{
		if (window->mlx_ptr)
		{
			mlx_destroy_display(window->mlx_ptr);
			free(window->mlx_ptr);
		}
		return (ERROR);
	}
	return (OK);
}
