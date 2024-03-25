/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:49 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 17:44:02 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_tiles(t_long *so_long)
{
	if (so_long->tiles.bush.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.bush.mlx_img);
	if (so_long->tiles.fence.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.fence.mlx_img);
	if (so_long->tiles.collectable.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.collectable.mlx_img);
	if (so_long->tiles.p_down.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.p_down.mlx_img);
	if (so_long->tiles.p_left.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.p_left.mlx_img);
	if (so_long->tiles.p_right.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.p_right.mlx_img);
	if (so_long->tiles.p_up.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.p_up.mlx_img);
	if (so_long->tiles.exit_open.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.exit_open.mlx_img);
	if (so_long->tiles.floor_dirt.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.floor_dirt.mlx_img);
	if (so_long->tiles.outw_corner_left.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_corner_left.mlx_img);
	if (so_long->tiles.outw_low.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_low.mlx_img);
	free_tiles_more(so_long);
}

void free_tiles_more(t_long *so_long)
{
	if (so_long->tiles.outw_left.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_left.mlx_img);
	if (so_long->tiles.outw_corner_right.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_corner_right.mlx_img);
	if (so_long->tiles.outw_right.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.outw_right.mlx_img);
	if (so_long->tiles.floor_flower.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.floor_flower.mlx_img);
	if (so_long->tiles.exit_close.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.exit_close.mlx_img);
	if (so_long->tiles.floor_plain.mlx_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->tiles.floor_plain.mlx_img);
	set_ptr_img_null(so_long);
}
