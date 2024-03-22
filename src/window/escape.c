/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:53 by phwang            #+#    #+#             */
/*   Updated: 2024/03/22 22:13:54 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_exit(int keysym, t_long *so_long)
{
	if (keysym == XK_Escape)
	{
		ft_printf("(ESC) key has been pressed ! bye\n");
		map_free(so_long, (so_long->map_size - 1));
		ft_destroy(so_long);
		exit (EXIT_SUCCESS);
	}
	return (ERROR);
}

int	cross_exit(t_long *so_long)
{
	if (so_long)
	{
		ft_printf("Cross has been clicked ! bye\n");
		map_free(so_long, (so_long->map_size - 1));
		ft_destroy(so_long);
		exit (EXIT_SUCCESS);
	}
	return (ERROR);
}
