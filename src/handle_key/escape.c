/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:53 by phwang            #+#    #+#             */
/*   Updated: 2024/03/17 23:37:10 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_exit(int keysym, t_win *window)
{
	if (keysym == XK_Escape)
	{
		ft_printf("(ESC) key has been pressed ! bye\n");
		ft_destroy(*window);
		exit (1);
	}
	return (0);
}

int cross_exit(t_win *window)
{
	if (window)
	{
		ft_printf("Cross has been clicked ! bye\n");
		ft_destroy(*window);
		exit (0);
	}
}
