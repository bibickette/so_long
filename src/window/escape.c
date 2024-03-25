/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:53 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 19:44:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_exit(int keysym, t_long *so_long)
{
	if (keysym == XK_Escape)
	{
		ft_printf("(ESC) key has been pressed ! bye\n");
		apocalypse(so_long);
		exit (EXIT_SUCCESS);
	}
	return (ERROR);
}

int	cross_exit(t_long *so_long)
{
	if (so_long)
	{
		ft_printf("Cross has been clicked ! bye\n");
		apocalypse(so_long);
		exit (EXIT_SUCCESS);
	}
	return (ERROR);
}
