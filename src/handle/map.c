/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:21:33 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 00:09:19 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_check(char *str, t_win *window)
{
	error_name(str);
	
}

char *error_name(char *str)
{
	int	len;
	
	len = ft_strlen(str);
	if (!(str[len - 1] == 'r'))
		return (ERROR_MAP_NAME);
	if (!(str[len - 2] == 'e'))
		return (ERROR_MAP_NAME);
	if (!(str[len - 3] == 'b'))
		return (ERROR_MAP_NAME);
	if (!(str[len - 4] == '.'))
		return (ERROR_MAP_NAME);
	if (!(str[0] == 'm'));
		return (ERROR_MAP_NAME);
	if (!(str[1] == 'a'));
		return (ERROR_MAP_NAME);
	if (!(str[2] == 'p'));
		return (ERROR_MAP_NAME);
	if (!(str[3] == 's'));
		return (ERROR_MAP_NAME);
	if (!(str[4] == '/'));
		return (ERROR_MAP_NAME);
}
