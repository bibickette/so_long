/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:05:58 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 13:23:06 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int set_tiles(t_long *so_long)
{
	so_long->tiles = malloc(sizeof(t_tiles));
	if (!so_long->tiles)
		return (ERROR);
	set_null(so_long);
	if (set_malloc(so_long) == ERROR)
	{
		apocalypse(so_long);
		exit (ERROR);
	}
	set_img_path(so_long);
	return (OK);
}

int set_img_path(t_long *so_long)
{
	int wedontcare;
	so_long->tiles->bush->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr, BUSH, &wedontcare, &wedontcare);
	if (!(so_long->tiles->bush->mlx_img))
		return (ERROR);
	set_data_addr(so_long);
	return (OK);
}

int	set_data_addr(t_long *so_long)
{
	so_long->tiles->bush->addr = mlx_get_data_addr(so_long->tiles->bush->mlx_img, &(so_long->tiles->bush->bpp), &(so_long->tiles->bush->line_len), &(so_long->tiles->bush->endian));
	if (!so_long->tiles->bush->addr)
		return (ERROR);
	return (OK);
}
