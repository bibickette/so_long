/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:20:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 18:17:39 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_destroy(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	free(so_long);
	so_long = 0;
}

int	create_window(t_long *so_long, char *str)
{
	so_long->mlx_ptr = mlx_init();
	if (!so_long->mlx_ptr)
		return (ERROR);
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, 64, 64, str);
	if (!so_long->win_ptr)
	{
		if (so_long->mlx_ptr)
		{
			mlx_destroy_display(so_long->mlx_ptr);
			free(so_long->mlx_ptr);
		}
		return (ERROR);
	}
	return (OK);
}
