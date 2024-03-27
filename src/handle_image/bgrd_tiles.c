/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgrd_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:05:58 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:16:20 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	set_tiles(t_long *so_long)
{
	static char	*dico[] = {
		BUSH, FENCE, COLLECTABLE, P_UP, P_DOWN, P_LEFT, P_RIGHT,
		EXIT_OPEN, EXIT_CLOSE, FLOOR_PLAIN, FLOOR_DIRT, FLOOR_FLOWER,
		OUTW_CORNER_RIGHT, OUTW_CORNER_LEFT, OUTW_LEFT, OUTW_RIGHT, OUTW_LOW, 0
	};

	so_long->tiles = ft_calloc(sizeof(dico) / sizeof(char *), sizeof(t_tile));
	if (!so_long->tiles)
		return (ERROR);
	load_n_set(so_long, dico);
	return (OK);
}

int	load_n_set(t_long *so_long, char **dico)
{
	int	i;
	int	wedontcare;

	wedontcare = 0;
	i = -1;
	while (dico[++i])
	{
		so_long->tiles[i].name = dico[i];
		so_long->tiles[i].img.mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
				dico[i], &wedontcare, &wedontcare);
		if (!(so_long->tiles[i].img.mlx_img))
			return (ERROR);
		so_long->tiles[i].img.addr = mlx_get_data_addr(
				so_long->tiles[i].img.mlx_img,
				&(so_long->tiles[i].img.bpp),
				&(so_long->tiles[i].img.line_len),
				&(so_long->tiles[i].img.endian));
	}
	return (OK);
}
