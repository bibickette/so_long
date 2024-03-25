/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:49 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 19:30:54 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

// void free_tiles_more(t_long *so_long)
// {
// 	if (so_long->tiles.outw_left.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_left.mlx_img);
// 	if (so_long->tiles.outw_corner_right.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_corner_right.mlx_img);
// 	if (so_long->tiles.outw_right.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_right.mlx_img);
// 	if (so_long->tiles.floor_flower.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.floor_flower.mlx_img);
// 	if (so_long->tiles.exit_close.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.exit_close.mlx_img);
// 	if (so_long->tiles.floor_plain.mlx_img)
// 		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.floor_plain.mlx_img);
// 	// set_ptr_img_null(so_long);
// }
