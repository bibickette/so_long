/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_bgrd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:16:06 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:21:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	set_backup_bgrd(t_long *so_long)
{
	so_long->backup.mlx_img = 0;
	so_long->backup.mlx_img = mlx_new_image(so_long->mlx_ptr,
			(so_long->map_len * IMG_WIDTH),
			(so_long->map_size * IMG_HEIGHT));
	if (!so_long->backup.mlx_img)
		return (ERROR);
	so_long->backup.addr = mlx_get_data_addr(so_long->backup.mlx_img,
			&(so_long->backup.bpp),
			&(so_long->backup.line_len),
			&(so_long->backup.endian));
	if (!so_long->backup.addr)
		return (ERROR);
	cpy_background(so_long);
	so_long->backup.addr = mlx_get_data_addr(so_long->backup.mlx_img,
			&(so_long->backup.bpp),
			&(so_long->backup.line_len),
			&(so_long->backup.endian));
	return (OK);
}

void	cpy_background(t_long *so_long)
{
	char			*pixel;
	unsigned int	color;
	int				x;
	int				y;

	y = -1;
	while (++y < (so_long->map_size * IMG_HEIGHT))
	{
		x = -1;
		while (++x < (so_long->map_len * IMG_WIDTH))
		{
			color = *(unsigned int *)(so_long->background.addr
					+ ((y * so_long->background.line_len
							+ x * ((so_long->background.bpp / 8)))));
			pixel = so_long->backup.addr + (y * so_long->backup.line_len
					+ x * (so_long->backup.bpp / 8));
			if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
		}
	}
}

void	put_backup(t_long *so_long, int where_x, int where_y)
{
	unsigned int	color;
	char			*pixel;
	int				x;
	int				y;

	y = -1;
	while (++y < IMG_HEIGHT)
	{
		x = -1;
		while (++x < IMG_WIDTH)
		{
			color = *(unsigned int *)(so_long->backup.addr
					+ (((y + where_y * IMG_HEIGHT) * so_long->backup.line_len
							+ (x + where_x * IMG_WIDTH)
							* ((so_long->backup.bpp / 8)))));
			pixel = so_long->background.addr + ((y + where_y * IMG_HEIGHT)
					* so_long->background.line_len + (x + where_x * IMG_WIDTH)
					* (so_long->background.bpp / 8));
			if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
		}
	}
}
