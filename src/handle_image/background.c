/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:12:11 by phwang            #+#    #+#             */
/*   Updated: 2024/03/26 18:21:41 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int background_creation(t_long *so_long)
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
	return (OK);
}

void	set_background(t_long *so_long)
{
	int x;
	int y;

	y = 0;
	while (y < (so_long->map_size))
	{
		x = 0;
		while (x <  (so_long->map_len))
		{
			choose_img(so_long, &x, &y);
			x++;
		}
		y++;
	}
}

void choose_img(t_long *so_long, int *x, int *y)
{
	if (*x != 0 && *x != so_long->map_len - 1 && *y != 0 && *y != so_long->map_size - 1)
		put_img(so_long, FLOOR_PLAIN, *x, *y);
	else
		{
			if ((*x == so_long->map_len - 1 && *y == so_long->map_size - 1))
				put_img(so_long, OUTW_CORNER_RIGHT, *x, *y);
			else if (*x == 0 && *y == so_long->map_size - 1)
				put_img(so_long, OUTW_CORNER_LEFT, *x, *y);
			else if (*x != 0 && *x != so_long->map_len - 1 && *y == so_long->map_size - 1)
				put_img(so_long, OUTW_LOW, *x, *y);
			else if (*x == so_long->map_len - 1 && *y != so_long->map_size -1)
				put_img(so_long, OUTW_RIGHT, *x, *y);
			else if (*x == 0 && *x != so_long->map_len - 1 && *y != so_long->map_size - 1)
				put_img(so_long, OUTW_LEFT, *x, *y);
			else if (*y == 0 && *x != 0 && *x != so_long->map_len - 1)
				put_img(so_long, BUSH, *x, *y);		
		}
}

void put_img(t_long *so_long, char *whatimg, int where_x, int where_y)
{
	unsigned int 	color;
	char 			*pixel;
	int 			x;
	int 			y;

	y = -1;
	while (++y < IMG_HEIGHT)
	{
		x = -1;
		while (++x < IMG_WIDTH)
		{
			color = *(unsigned int *)((search_img(so_long, whatimg))->addr 
					+ ((y * (search_img(so_long, whatimg))->line_len 
					+ x * ((search_img(so_long, whatimg))->bpp / 8))));
			pixel = so_long->background.addr + ((y + where_y * IMG_HEIGHT)
					* so_long->background.line_len + (x + where_x * IMG_WIDTH)
					* (so_long->background.bpp / 8));
			if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
		}
	}
}

t_img	*search_img(t_long *so_long, char *img_wanted)
{
	t_img	*wanted;
	int		i;

	i = 0;
	while (so_long->tiles[i].name)
	{
		if (ft_strncmp(so_long->tiles[i].name,
		img_wanted, ft_strlen(img_wanted)) == 0)
			wanted = &so_long->tiles[i].img;
		i++;
	}
	return (wanted);
}
