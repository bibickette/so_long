/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgrd_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:26:58 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:13:16 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_img(t_long *so_long, t_img *whatimg, int where_x, int where_y)
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
			color = *(unsigned int *)(whatimg->addr + ((y * whatimg->line_len
							+ x * ((whatimg->bpp / 8)))));
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

	i = -1;
	while (so_long->tiles[++i].name)
		if (ft_strncmp(so_long->tiles[i].name, img_wanted,
				ft_strlen(img_wanted)) == 0)
			wanted = &so_long->tiles[i].img;
	return (wanted);
}
