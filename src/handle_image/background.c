/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:12:11 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:18:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	background_creation(t_long *so_long)
{
	so_long->background.mlx_img = 0;
	so_long->background.mlx_img = mlx_new_image(so_long->mlx_ptr,
			(so_long->map_len * IMG_WIDTH),
			(so_long->map_size * IMG_HEIGHT));
	if (!so_long->background.mlx_img)
		return (ERROR);
	so_long->background.addr = mlx_get_data_addr(so_long->background.mlx_img,
			&(so_long->background.bpp),
			&(so_long->background.line_len),
			&(so_long->background.endian));
	if (!so_long->background.addr)
		return (ERROR);
	if (set_tiles(so_long) == ERROR)
		return (ERROR);
	set_background(so_long);
	set_backup_bgrd(so_long);
	set_foreground(so_long);
	return (OK);
}

void	set_background(t_long *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (so_long->map_size))
	{
		x = -1;
		while (++x < (so_long->map_len))
		{
			if (x != 0 && x != so_long->map_len - 1
				&& y != 0 && y != so_long->map_size - 1)
				put_inside(so_long, &x, &y);
			else
				put_outside(so_long, &x, &y);
		}
	}
}

void	put_outside(t_long *so_long, int *x, int *y)
{
	if ((*x == so_long->map_len - 1 && *y == so_long->map_size - 1))
		put_img(so_long, search_img(so_long, OUTW_CORNER_RIGHT), *x, *y);
	else if (*x == 0 && *y == so_long->map_size - 1)
		put_img(so_long, search_img(so_long, OUTW_CORNER_LEFT), *x, *y);
	else if (*x != 0 && *x != so_long->map_len - 1
		&& *y == so_long->map_size - 1)
		put_img(so_long, search_img(so_long, OUTW_LOW), *x, *y);
	else if (*x == so_long->map_len - 1 && *y != so_long->map_size -1)
		put_img(so_long, search_img(so_long, OUTW_RIGHT), *x, *y);
	else if (*x == 0 && *x != so_long->map_len - 1
		&& *y != so_long->map_size - 1)
		put_img(so_long, search_img(so_long, OUTW_LEFT), *x, *y);
	else if (*y == 0 && *x != 0 && *x != so_long->map_len - 1)
		put_img(so_long, search_img(so_long, BUSH), *x, *y);
}

void	put_inside(t_long *so_long, int *x, int *y)
{
	int	random;

	random = rand() % 10;
	if (so_long->map[*y][*x] == FLOOR || so_long->map[*y][*x] == ITEM
	|| so_long->map[*y][*x] == PLAYER)
	{
		if (random <= 6 && random > 1)
			put_img(so_long, search_img(so_long, FLOOR_PLAIN), *x, *y);
		else if (random == 9)
			put_img(so_long, search_img(so_long, FLOOR_DIRT), *x, *y);
		else if (!(random <= 6 && random > 1))
			put_img(so_long, search_img(so_long, FLOOR_FLOWER), *x, *y);
	}
	else if (so_long->map[*y][*x] == WALL)
	{
		if ((so_long->map[*y][*x] == WALL && so_long->map[*y + 1][*x] == WALL)
		|| (so_long->map[*y][*x] == WALL && so_long->map[*y - 1][*x] == WALL))
			put_img(so_long, search_img(so_long, FENCE), *x, *y);
		else
			put_img(so_long, search_img(so_long, BUSH), *x, *y);
	}
	else if (so_long->map[*y][*x] == DOOR)
		put_img(so_long, search_img(so_long, EXIT_CLOSE), *x, *y);
}
