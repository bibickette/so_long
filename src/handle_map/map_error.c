/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:39:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/26 18:35:49 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	msg_error(char *error_msg, int msgflag)
{
	if (msgflag == 1)
		ft_printf("%s", error_msg);
	exit (EXIT_FAILURE);
}

void	map_free(t_long *so_long, int nb_tab)
{
	while (nb_tab >= 0)
	{
		free(so_long->map[nb_tab]);
		nb_tab--;
	}
	free(so_long->map);
	so_long->map = 0;
}
