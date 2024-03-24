/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:49 by phwang            #+#    #+#             */
/*   Updated: 2024/03/24 19:29:24 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_tiles(t_long *so_long)
{
	if (so_long->tiles->bush)
	{
		if (so_long->tiles->bush->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->bush->mlx_img);
		free(so_long->tiles->bush);
		so_long->tiles->bush = 0;
	}
	if (so_long->tiles->fence)
	{
		if (so_long->tiles->fence->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr, so_long->tiles->fence->mlx_img);
		free(so_long->tiles->fence);
		so_long->tiles->fence = 0;
	}
	if (so_long->tiles->collectable)
	{
		if (so_long->tiles->collectable->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
			so_long->tiles->collectable->mlx_img);
		free(so_long->tiles->collectable);
		so_long->tiles->collectable = 0;
	}
	free_tiles_more(so_long);
}

void free_tiles_more(t_long *so_long)
{
	if (so_long->tiles->p_down)
	{
		if (so_long->tiles->p_down->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->p_down->mlx_img);
		free(so_long->tiles->p_down);
		so_long->tiles->p_down = 0;
	}
	if (so_long->tiles->p_left)
	{
		if (so_long->tiles->p_left->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->p_left->mlx_img);
		free(so_long->tiles->p_left);
		so_long->tiles->p_left = 0;
	}
	if (so_long->tiles->p_right)
	{
		if (so_long->tiles->p_right->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->p_right->mlx_img);
		free(so_long->tiles->p_right);
		so_long->tiles->p_right = 0;
	}
	free_tiles_expanded(so_long);
}

void free_tiles_expanded(t_long *so_long)
{
	if (so_long->tiles->p_up)
	{
		if (so_long->tiles->p_up->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->p_up->mlx_img);
		free(so_long->tiles->p_up);
		so_long->tiles->p_up = 0;
	}
	if (so_long->tiles->exit_open)
	{
		if (so_long->tiles->exit_open->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->exit_open->mlx_img);
		free(so_long->tiles->exit_open);
		so_long->tiles->exit_open = 0;
	}
	if (so_long->tiles->floor_dirt)
	{
		if (so_long->tiles->floor_dirt->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->floor_dirt->mlx_img);
		free(so_long->tiles->floor_dirt);
		so_long->tiles->floor_dirt = 0;
	}
	free_tiles_super(so_long);
}

void	free_tiles_super(t_long *so_long)
{
	if (so_long->tiles->outw_corner_left)
	{
		if (so_long->tiles->outw_corner_left->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->outw_corner_left->mlx_img);
		free(so_long->tiles->outw_corner_left);
		so_long->tiles->outw_corner_left = 0;
	}
	if (so_long->tiles->outw_low)
	{
		if (so_long->tiles->outw_low->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->outw_low->mlx_img);
		free(so_long->tiles->outw_low);
		so_long->tiles->outw_low = 0;
	}
	if (so_long->tiles->outw_left)
	{
		if (so_long->tiles->outw_left->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr,
				so_long->tiles->outw_left->mlx_img);
		free(so_long->tiles->outw_left);
		so_long->tiles->outw_left = 0;
	}
	free_tiles_supra(so_long);
}
