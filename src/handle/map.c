/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:21:33 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 18:54:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_check(int argc, char **argv, t_long *so_long)
{
	char	*big_line_map;
	
	if (argc != 2)
		exit (EXIT_FAILURE);
	error_name(argv[1]);
	big_line_map = malloc(sizeof(char));
	
	if (!big_line_map)
		exit (EXIT_FAILURE);
	put_in_one_bigline(argv[1], big_line_map);
}

void msg_error(char *error_msg)
{
	ft_printf("%s", error_msg);
	exit (EXIT_FAILURE);
}

int put_in_one_bigline(char *map_name, char *big_line_map)
{
	int		map_fd;
	char 	*readed;

	map_fd = open(map_name, O_RDONLY);
	while (1)
	{
		readed = get_next_line(map_fd);
		if (readed == NULL)
			break;
		big_line_map = ft_strjoin(big_line_map, readed);
		if (readed)
			free(readed);
	}
	close(map_fd);
	free(big_line_map);
	return (OK);
}

void error_name(char *str)
{
	int	len;
	
	len = ft_strlen(str);
	if (!(str[len - 1] == 'r'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[len - 2] == 'e'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[len - 3] == 'b'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[len - 4] == '.'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[0] == 'm'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[1] == 'a'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[2] == 'p'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[3] == 's'))
		msg_error(ERROR_MAP_NAME);
	if (!(str[4] == '/'))
		msg_error(ERROR_MAP_NAME);
}
