/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:39:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 20:42:38 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	msg_error(char *error_msg, t_long *so_long)
{
	ft_printf("%s", error_msg);
	free(so_long);
	so_long = 0;
	exit (EXIT_FAILURE);
}

void	handle_error_free(t_long *so_long)
{
	free(so_long);
	so_long = 0;
	exit (EXIT_FAILURE);
}
