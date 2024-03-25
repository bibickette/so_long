/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:04:09 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 19:34:36 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_destroy(t_long *so_long)
{
	if (so_long->win_ptr)
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	if (so_long->mlx_ptr)
		mlx_destroy_display(so_long->mlx_ptr);
	if (so_long->mlx_ptr)
		free(so_long->mlx_ptr);
	// free(so_long);
	// so_long = 0;
	exit (0);
}
