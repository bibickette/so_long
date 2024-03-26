/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:20:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/26 18:15:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	create_window(t_long *so_long, char *str)
{
	so_long->mlx_ptr = mlx_init();
	if (!so_long->mlx_ptr)
		return (ERROR);
	if (background_creation(so_long) == ERROR)
		return (ERROR);
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, (so_long->map_len * IMG_WIDTH), (so_long->map_size * IMG_HEIGHT), str);
	if (!so_long->win_ptr)
	{
		apocalypse(so_long);
		return (ERROR);
	}
	return (OK);
}
