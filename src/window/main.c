/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:04:29 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 18:13:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_long *so_long;

	so_long = malloc(sizeof(t_long));
	map_check(argc, argv, so_long);
	if (create_window(so_long, "Very very long") == ERROR)
		return (ERROR);
	mlx_key_hook(so_long->win_ptr, &esc_exit, so_long);
	mlx_hook(so_long->win_ptr, 17, 0, &cross_exit, so_long);
	mlx_loop(so_long->mlx_ptr);
	ft_destroy(so_long);
}
