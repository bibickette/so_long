/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:39:24 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 20:06:27 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void set_foreground(t_long *so_long)
{
	put_img(so_long, search_img(so_long, P_DOWN), so_long->player_x, so_long->player_y);
	put_collectable(so_long);
}

void put_collectable(t_long *so_long)
{
	int x;
	int y;
	
	y = -1;
	while (++y < so_long->map_size)
	{
		x = -1;
		while (++x < so_long->map_len)
			if (so_long->map[y][x] == ITEM)
				put_img(so_long, search_img(so_long, COLLECTABLE), x, y);
	}
}

void	step_n_item(t_long *so_long, int x, int y)
{
	so_long->step++;
	if (so_long->step == 1)
		ft_printf("First step ! Like a baby \n");
	else
		ft_printf("Steps = %d\n", so_long->step);
	if (so_long->map[y][x] == ITEM)
	{
		so_long->collectable--;
		so_long->map[y][x] = FLOOR;
		if (so_long->collectable == 1)
			ft_printf("You need one more diamond\n");
		else if (so_long->collectable == 0)
			ft_printf("You have theim all ! Go to the exit !\n");
		else if (so_long->collectable > 1)
			ft_printf("You need %d more diamonds\n", so_long->collectable);
	}
}
