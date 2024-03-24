/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:03:45 by phwang            #+#    #+#             */
/*   Updated: 2024/03/24 20:12:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void apocalypse(t_long *so_long)
{
	free_background(so_long);
	map_free(so_long, (so_long->map_size - 1));
	ft_destroy(so_long);
}
