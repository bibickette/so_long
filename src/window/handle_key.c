/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:53 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 19:08:27 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	handle_key(int keysym, t_long *so_long)
{
	if (keysym == XK_z || keysym == XK_Up || keysym == XK_w)
		move_up(so_long);
	else if (keysym == XK_s || keysym == XK_Down)
		move_down(so_long);
	else if (keysym == XK_q || keysym == XK_Left || keysym == XK_a)
		move_left(so_long);
	else if (keysym == XK_d || keysym == XK_Right)
		move_right(so_long);
	else if (keysym == XK_Escape)
	{
		ft_printf("(ESC) key has been pressed ! bye\n");
		apocalypse(so_long);
	}
	handle_end(so_long);
	return (ERROR);
}

int	cross_exit(t_long *so_long)
{
	if (so_long)
	{
		ft_printf("Cross has been clicked ! bye\n");
		apocalypse(so_long);
	}
	return (ERROR);
}

void	handle_end(t_long *so_long)
{
	if (so_long->map[so_long->player_y ][so_long->player_x] == DOOR)
	{
		ft_printf("You found the escape ! bye\n");
		apocalypse(so_long);
	}	
}
