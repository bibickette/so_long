/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:21:33 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 19:07:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	set_map(int argc, char **argv, t_long *so_long)
{
	char	*big_line_map;

	if (argc != 2)
		exit (EXIT_FAILURE);
	so_long->mlx_ptr = 0;
	check_path_name(argv[1]);
	if (put_in_one_bigline(argv[1], &big_line_map) == ERROR)
		apocalypse(so_long);
	so_long->map = ft_split(big_line_map, '\n');
	if (so_long->map == 0)
	{
		free(big_line_map);
		apocalypse(so_long);
	}
	free(big_line_map);
	check_map(so_long);
}

int	put_in_one_bigline(char *map_name, char **big_line_map)
{
	int		map_fd;
	char	*readed;

	map_fd = open(map_name, O_RDONLY);
	*big_line_map = 0;
	while (1)
	{
		readed = get_next_line(map_fd);
		if (readed == NULL)
			break ;
		*big_line_map = long_join(*big_line_map, readed);
		if (*big_line_map == 0)
		{
			free(readed);
			return (ERROR);
		}
		if (readed)
			free(readed);
	}
	close(map_fd);
	return (OK);
}

char	*long_join(char *backup, char *buffer)
{
	char	*str;

	if (!backup)
	{
		backup = malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buffer)
	{
		if (backup)
			free(backup);
		return (0);
	}
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buffer)) + 1));
	if (!str)
	{
		if (backup)
			free(backup);
		return (0);
	}
	str = heedz_join(str, backup, buffer);
	free(backup);
	return (str);
}

char	*heedz_join(char *str, char *backup, char *buffer)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (backup[++i])
		str[i] = backup[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	return (str);
}
