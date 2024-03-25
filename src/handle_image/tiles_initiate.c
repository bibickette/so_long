/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_initiate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:13:09 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 18:48:04 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// int	set_malloc(t_long *so_long)
// {
// 	so_long->tiles->bush = malloc(sizeof(t_img));
// 	so_long->tiles->collectable = malloc(sizeof (t_img));
// 	so_long->tiles->p_down = malloc(sizeof (t_img));
// 	so_long->tiles->p_left = malloc(sizeof (t_img));
// 	so_long->tiles->p_right = malloc(sizeof (t_img));
// 	so_long->tiles->p_up = malloc(sizeof (t_img));
// 	so_long->tiles->exit_close = malloc(sizeof (t_img));
// 	so_long->tiles->exit_open = malloc(sizeof (t_img));
// 	so_long->tiles->fence = malloc(sizeof (t_img));
// 	so_long->tiles->floor_dirt = malloc(sizeof (t_img));
// 	so_long->tiles->floor_flower = malloc(sizeof (t_img));
// 	so_long->tiles->floor_plain = malloc(sizeof (t_img));
// 	so_long->tiles->outw_corner_left = malloc(sizeof (t_img));
// 	so_long->tiles->outw_corner_right = malloc(sizeof (t_img));
// 	so_long->tiles->outw_low = malloc(sizeof (t_img));
// 	so_long->tiles->outw_right = malloc(sizeof (t_img));
// 	so_long->tiles->outw_left = malloc(sizeof (t_img));
// 	set_ptr_img_null(so_long);
// 	if (check_malloc_error(so_long) == ERROR)
// 		return (ERROR);
// 	return (OK);
// }

// int	check_malloc_error(t_long *so_long)
// {
// 	if (!(so_long->tiles->bush || so_long->tiles->collectable ||
// 		so_long->tiles->p_down || so_long->tiles->p_left ||
// 		so_long->tiles->p_right || so_long->tiles->p_up ||
// 		so_long->tiles->exit_close || so_long->tiles->exit_open ||
// 		so_long->tiles->fence || so_long->tiles->floor_dirt ||
// 		so_long->tiles->floor_flower || so_long->tiles->floor_plain ||
// 		so_long->tiles->outw_corner_left || so_long->tiles->outw_corner_right ||
// 		so_long->tiles->outw_low || so_long->tiles->outw_right ||
// 		so_long->tiles->outw_left))
// 			return (ERROR);
// 	return (OK);
// }

// void	set_null(t_long *so_long)
// {
// 	so_long->tiles->bush = 0;
// 	so_long->tiles->collectable = 0;
// 	so_long->tiles->p_down = 0;
// 	so_long->tiles->p_left = 0;
// 	so_long->tiles->p_right = 0;
// 	so_long->tiles->p_up = 0;
// 	so_long->tiles->exit_close = 0;
// 	so_long->tiles->exit_open = 0;
// 	so_long->tiles->fence = 0;
// 	so_long->tiles->floor_dirt = 0;
// 	so_long->tiles->floor_flower = 0;
// 	so_long->tiles->floor_plain = 0;
// 	so_long->tiles->outw_corner_left = 0;
// 	so_long->tiles->outw_corner_right = 0;
// 	so_long->tiles->outw_low = 0;
// 	so_long->tiles->outw_right = 0;
// 	so_long->tiles->outw_left = 0;
// }

// void set_ptr_img_null(t_long *so_long)
// {
// 	so_long->tiles.bush.mlx_img = 0;
// 	so_long->tiles.collectable.mlx_img = 0;
// 	so_long->tiles.p_down.mlx_img = 0;
// 	so_long->tiles.p_left.mlx_img = 0;
// 	so_long->tiles.p_right.mlx_img = 0;
// 	so_long->tiles.p_up.mlx_img = 0;
// 	so_long->tiles.exit_close.mlx_img = 0;
// 	so_long->tiles.exit_open.mlx_img = 0;
// 	so_long->tiles.fence.mlx_img = 0;
// 	so_long->tiles.floor_dirt.mlx_img = 0;
// 	so_long->tiles.floor_flower.mlx_img = 0;
// 	so_long->tiles.floor_plain.mlx_img = 0;
// 	so_long->tiles.outw_corner_left.mlx_img = 0;
// 	so_long->tiles.outw_corner_right.mlx_img = 0;
// 	so_long->tiles.outw_low.mlx_img = 0;
// 	so_long->tiles.outw_right.mlx_img = 0;
// 	so_long->tiles.outw_left.mlx_img = 0;
// }
