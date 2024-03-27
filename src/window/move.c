/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:13:19 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:24:11 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_long *so_long)
{
	if (so_long->map[so_long->player_y - 1][so_long->player_x] == DOOR
		&& so_long->collectable != 0)
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_UP),
			so_long->player_x, so_long->player_y);
		ft_printf("You need to have all the diamonds to leave\n");
	}
	else if (so_long->map[so_long->player_y - 1][so_long->player_x] == DOOR
		&& so_long->collectable == 0)
		handle_end(so_long);
	else if (so_long->map[so_long->player_y - 1][so_long->player_x] != WALL)
	{
		put_img(so_long, search_img(so_long, P_UP),
			so_long->player_x, so_long->player_y - 1);
		put_backup(so_long, so_long->player_x, so_long->player_y);
		so_long->player_y--;
		step_n_item(so_long, so_long->player_x, so_long->player_y);
	}
	else
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_UP),
			so_long->player_x, so_long->player_y);
	}
}

void	move_down(t_long *so_long)
{
	if (so_long->map[so_long->player_y + 1][so_long->player_x] == DOOR
		&& so_long->collectable != 0)
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_DOWN),
			so_long->player_x, so_long->player_y);
		ft_printf("You need to have all the diamonds to leave\n");
	}
	else if (so_long->map[so_long->player_y + 1][so_long->player_x] == DOOR
		&& so_long->collectable == 0)
		handle_end(so_long);
	else if (so_long->map[so_long->player_y + 1][so_long->player_x] != WALL)
	{
		put_img(so_long, search_img(so_long, P_DOWN),
			so_long->player_x, so_long->player_y + 1);
		put_backup(so_long, so_long->player_x, so_long->player_y);
		so_long->player_y++;
		step_n_item(so_long, so_long->player_x, so_long->player_y);
	}
	else
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_DOWN),
			so_long->player_x, so_long->player_y);
	}
}

void	move_left(t_long *so_long)
{
	if (so_long->map[so_long->player_y][so_long->player_x - 1] == DOOR
		&& so_long->collectable != 0)
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_LEFT),
			so_long->player_x, so_long->player_y);
		ft_printf("You need to have all the diamonds to leave\n");
	}
	else if (so_long->map[so_long->player_y][so_long->player_x - 1] == DOOR
		&& so_long->collectable == 0)
		handle_end(so_long);
	else if (so_long->map[so_long->player_y][so_long->player_x - 1] != WALL)
	{
		put_img(so_long, search_img(so_long, P_LEFT),
			so_long->player_x - 1, so_long->player_y);
		put_backup(so_long, so_long->player_x, so_long->player_y);
		so_long->player_x--;
		step_n_item(so_long, so_long->player_x, so_long->player_y);
	}
	else
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_LEFT),
			so_long->player_x, so_long->player_y);
	}
}

void	move_right(t_long *so_long)
{
	if (so_long->map[so_long->player_y][so_long->player_x + 1] == DOOR
		&& so_long->collectable != 0)
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_RIGHT),
			so_long->player_x, so_long->player_y);
		ft_printf("You need to have all the diamonds to leave\n");
	}
	else if (so_long->map[so_long->player_y][so_long->player_x + 1] == DOOR
		&& so_long->collectable == 0)
		handle_end(so_long);
	else if (so_long->map[so_long->player_y][so_long->player_x + 1] != WALL)
	{
		put_img(so_long, search_img(so_long, P_RIGHT),
			so_long->player_x + 1, so_long->player_y);
		put_backup(so_long, so_long->player_x, so_long->player_y);
		so_long->player_x++;
		step_n_item(so_long, so_long->player_x, so_long->player_y);
	}
	else
	{
		put_backup(so_long, so_long->player_x, so_long->player_y);
		put_img(so_long, search_img(so_long, P_RIGHT),
			so_long->player_x, so_long->player_y);
	}
}
