/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:20:41 by phwang            #+#    #+#             */
/*   Updated: 2024/03/22 22:14:25 by phwang           ###   ########.fr       */
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
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, 300, 300, str);
	if (!so_long->win_ptr)
	{
		ft_destroy(so_long);
		return (ERROR);
	}
	return (OK);
}
