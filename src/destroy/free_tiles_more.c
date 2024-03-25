/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiles_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:23:18 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 13:31:00 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void free_tiles_supra(t_long *so_long)
{
	if (so_long->tiles->outw_corner_right)
	{
		if (so_long->tiles->outw_corner_right->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->outw_corner_right->mlx_img);
		free(so_long->tiles->outw_corner_right);
		so_long->tiles->outw_corner_right = 0;
	}
	if (so_long->tiles->outw_right)
	{
		if (so_long->tiles->outw_right->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->outw_right->mlx_img);
		free(so_long->tiles->outw_right);
		so_long->tiles->outw_right = 0;
	}
	if (so_long->tiles->floor_flower)
	{
		if (so_long->tiles->floor_flower->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->floor_flower->mlx_img);
		free(so_long->tiles->floor_flower);
		so_long->tiles->floor_flower = 0;
	}
	free_tiles_final(so_long);
}

void	free_tiles_final(t_long *so_long)
{
	if (so_long->tiles->exit_close)
	{
		if (so_long->tiles->exit_close->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->exit_close->mlx_img);
		free(so_long->tiles->exit_close);
		so_long->tiles->exit_close = 0;
	}
	if (so_long->tiles->floor_plain)
	{
		if (so_long->tiles->floor_plain->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->floor_plain->mlx_img);
		free(so_long->tiles->floor_plain);
		so_long->tiles->floor_plain = 0;
	}
	if (so_long->tiles)
	{
		free(so_long->tiles);
		so_long->tiles = 0;
	}
}
