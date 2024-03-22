/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:36:51 by phwang            #+#    #+#             */
/*   Updated: 2024/03/22 20:38:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_nb_item(t_long *so_long)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	i = -1;
	exit = 0;
	player = 0;
	while (++i < (so_long->map_size))
	{
		j = -1;
		while (++j < (so_long->map_len))
		{
			if (so_long->map[i][j] == 'E')
				exit++;
			if (so_long->map[i][j] == 'P')
				player++;
		}
	}
	if (exit != 1 || player != 1)
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
			if (so_long->map[i][j] == 'C')
				obj++;
	}
	if (obj < 1)
		return (ERROR);
	so_long->collectable = obj;
	return (OK);
}
