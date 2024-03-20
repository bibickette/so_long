/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:21:33 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 20:44:32 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_check(int argc, char **argv, t_long **so_long)
{
	char	*big_line_map;
	
	if (argc != 2)
		exit (EXIT_FAILURE);
	error_name(argv[1], *so_long);
	big_line_map = ft_strdup("");
	if (!big_line_map)
		handle_error_free(*so_long);
	if (put_in_one_bigline(argv[1], &big_line_map) == ERROR)
		handle_error_free(*so_long);
}

int put_in_one_bigline(char *map_name, char **big_line_map)
{
	int		map_fd;
	char 	*readed;

	map_fd = open(map_name, O_RDONLY);
	while (1)
	{
		readed = get_next_line(map_fd);
		if (readed == NULL)
			break;
		*big_line_map = ft_strjoin_solong(*big_line_map, readed);
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

void error_name(char *str, t_long *so_long)
{
	int	len;
	
	len = ft_strlen(str);
	if (!(str[len - 1] == 'r'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[len - 2] == 'e'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[len - 3] == 'b'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[len - 4] == '.'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[0] == 'm'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[1] == 'a'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[2] == 'p'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[3] == 's'))
		msg_error(ERROR_MAP_NAME, so_long);
	if (!(str[4] == '/'))
		msg_error(ERROR_MAP_NAME, so_long);
}
