/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:03:45 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 19:45:51 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void apocalypse(t_long *so_long)
{
	if (so_long->tiles)
		free_tiles(so_long);
	free_background(so_long);
	map_free(so_long, (so_long->map_size - 1));
	ft_destroy(so_long);
}

void	free_tiles(t_long *so_long)
{
	int i;

	i = 0;
	while (so_long->tiles[i].name)
	{
		if (so_long->tiles[i].img.mlx_img)
			mlx_destroy_image(so_long->mlx_ptr, so_long->tiles[i].img.mlx_img);
		i++;
	}
	free(so_long->tiles);
	so_long->tiles = 0;
}

void	ft_destroy(t_long *so_long)
{
	if (so_long->win_ptr)
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	if (so_long->mlx_ptr)
		mlx_destroy_display(so_long->mlx_ptr);
	if (so_long->mlx_ptr)
		free(so_long->mlx_ptr);
	exit (0);
}

void free_background(t_long *so_long)
{
	if (so_long->background.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->background.mlx_img);
}
