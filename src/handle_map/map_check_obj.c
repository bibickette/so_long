/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:36:51 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 00:30:09 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_nb_item(t_long *so_long)
{
	int	i;
	int	j;

	i = -1;
	so_long->player = 0;
	so_long->exit = 0;
	while (++i < (so_long->map_size))
	{
		j = -1;
		while (++j < (so_long->map_len))
			check_player_exit(so_long, &j, &i);
	}
	if (so_long->exit != 1 || so_long->player != 1)
		return (ERROR);
	if (check_collectable(so_long) == ERROR)
		return (ERROR);
	return (OK);
}

int	check_collectable(t_long *so_long)
{
	int	obj;
	int	i;
	int	j;

	i = -1;
	obj = 0;
	while (++i < (so_long->map_size))
	{
		j = -1;
		while (++j < (so_long->map_len))
		{
			if (so_long->map[i][j] == ITEM)
				obj++;
			if (so_long->map[i][j] != ITEM && so_long->map[i][j] != PLAYER
			&& so_long->map[i][j] != DOOR && so_long->map[i][j] != FLOOR
			&& so_long->map[i][j] != WALL)
				return (ERROR);
		}
	}
	if (obj < 1)
		return (ERROR);
	so_long->collectable = obj;
	return (OK);
}

void	check_player_exit(t_long *so_long, int *x, int *y)
{
	if (so_long->map[*y][*x] == DOOR)
	{
		so_long->exit_x = *x;
		so_long->exit_y = *y;
		so_long->exit++;
	}
	if (so_long->map[*y][*x] == PLAYER)
	{
		so_long->player_x = *x;
		so_long->player_y = *y;
		so_long->player++;
	}
}
