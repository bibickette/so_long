/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:12:11 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 21:11:50 by phwang           ###   ########.fr       */
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
			color = *(unsigned int *)((search_img(so_long, FENCE))->addr + ((y * (search_img(so_long, FENCE))->line_len + x * ((search_img(so_long, FENCE))->bpp / 8))));
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

t_img	*search_img(t_long *so_long, char *img_wanted)
{
	t_img	*wanted;
	int		i;

	i = 0;
	while (so_long->tiles[i].name)
	{
		if (ft_strncmp(so_long->tiles[i].name, img_wanted, ft_strlen(img_wanted)) == 0)
			wanted = &so_long->tiles[i].img;
		i++;
	}
	return (wanted);
}
