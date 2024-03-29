/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:21:18 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 19:11:04 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_map(t_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
		i++;
	so_long->step = 0;
	so_long->map_size = i;
	if ((i < 3)
		|| (check_map_len(so_long) == ERROR)
		|| (check_map_walls(so_long) == ERROR)
		|| (check_nb_item(so_long) == ERROR))
	{
		map_free(so_long, (i - 1));
		msg_error(ERROR_MAP_CONTENT);
	}
}

int	check_map_walls(t_long *so_long)
{
	int	i;

	i = -1;
	while (++i < so_long->map_len)
		if (so_long->map[0][i] != WALL
		|| so_long->map[(so_long->map_size - 1)][i] != WALL)
			return (ERROR);
	i = -1;
	while (++i < so_long->map_size)
		if (so_long->map[i][0] != WALL
		|| so_long->map[i][(so_long->map_len - 1)] != WALL)
			return (ERROR);
	return (OK);
}

int	check_map_len(t_long *so_long)
{
	int	i;
	int	tmp_i;
	int	tmp_len;

	i = 0;
	tmp_i = 0;
	while (so_long->map[0][tmp_i])
		tmp_i++;
	while (++i < so_long->map_size)
	{
		tmp_len = 0;
		while (so_long->map[i][tmp_len])
			tmp_len++;
		if (tmp_i != tmp_len)
			return (ERROR);
	}
	if (tmp_i < 5)
		return (ERROR);
	so_long->map_len = tmp_i;
	return (OK);
}

void	check_path_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!((str[len - 4] == '.')
			|| (str[len - 3] == 'b')
			|| (str[len - 2] == 'e')
			|| (str[len - 1] == 'r')))
		msg_error(ERROR_MAP_NAME);
	if (!((str[0] == 'm')
			|| (str[1] == 'a')
			|| (str[2] == 'p')
			|| (str[3] == 's')
			|| (str[4] == '/')))
		msg_error(ERROR_MAP_NAME);
}
