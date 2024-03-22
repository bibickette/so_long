/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:21:33 by phwang            #+#    #+#             */
/*   Updated: 2024/03/22 20:55:54 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	set_map(int argc, char **argv, t_long **so_long)
{
	char	*big_line_map;

	if (argc != 2)
		exit (EXIT_FAILURE);
	check_path_name(argv[1], *so_long);
	big_line_map = ft_strdup("");
	if (!big_line_map)
		msg_error(ERROR_MSG, *so_long, 0);
	if (put_in_one_bigline(argv[1], &big_line_map) == ERROR)
		msg_error(ERROR_MSG, *so_long, 0);
	(*so_long)->map = ft_split(big_line_map, '\n');
	if ((*so_long)->map == 0)
	{
		free(so_long);
		*so_long = 0;
		exit (EXIT_FAILURE);
	}
	free(big_line_map);
	check_map(so_long);
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
		*big_line_map = heedz_join(*big_line_map, readed);
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

char    *heedz_join(char *backup, char *buffer)
{
    size_t    i;
    size_t    j;
    char    *str;

    if (!backup)
    {
        backup = malloc(1 * sizeof(char));
        backup[0] = '\0';
    }
    if (!backup || !buffer)
        return (0);
    str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buffer)) + 1));
    if (!str)
        return (0);
    i = -1;
    j = 0;
    if (backup)
        while (backup[++i] != '\0')
            str[i] = backup[i];
    while (buffer[j] != '\0')
        str[i++] = buffer[j++];
    str[i] = '\0';
    free(backup);
    return (str);
}
