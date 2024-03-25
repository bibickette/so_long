/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:12:11 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 19:40:38 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int background_creation(t_long *so_long)
{
	so_long->background.mlx_img = 0;
	so_long->background.mlx_img = mlx_new_image(so_long->mlx_ptr, (so_long->map_len * IMG_WIDTH), (so_long->map_size * IMG_HEIGHT));
	if (!so_long->background.mlx_img)
		return (ERROR);
	so_long->background.addr = mlx_get_data_addr(so_long->background.mlx_img, &(so_long->background.bpp), &(so_long->background.line_len), &(so_long->background.endian));
	if (!so_long->background.addr)
		return (ERROR);
	set_tiles(so_long);
	set_background(so_long);
	return (OK);
}

int set_background(t_long *so_long)
{
	char *pixel = NULL;
	int x = 0;
	int y = 0;
	unsigned int color;
	while (y < IMG_HEIGHT * so_long->map_size)
	{
		x = 0;
		while (x < IMG_WIDTH * so_long->map_len)
		{
			if (x < IMG_WIDTH && y < IMG_HEIGHT)
			{
			color = *(unsigned int *)(so_long->tiles[0].img.addr + ((y * so_long->tiles[0].img.line_len + x * (so_long->tiles[0].img.bpp / 8))));
			pixel = so_long->background.addr + (y * so_long->background.line_len + x * (so_long->background.bpp / 8));
			if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
			}
			x++;
		}
		y++;
	}
	return (OK);
}
