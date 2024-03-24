/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:48:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/24 18:04:28 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void free_background(t_long *so_long)
{
	if (so_long->background->mlx_img)
	{
		mlx_destroy_image(so_long->mlx_ptr, so_long->background->mlx_img);
		free(so_long->background);
		so_long->background = 0;
	}
}
