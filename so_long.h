/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 01:29:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "LIBFT_PERSO/ft_printf/ft_printf.h"
# include "LIBFT_PERSO/get_next_line.h"
# include "LIBFT_PERSO/libft.h"
# include "minilibx-linux/mlx.h"

# define OK 1
# define ERROR -1
# define ERROR_MSG "Error\n"
# define ERROR_MAP_NAME "Map name/extension has error !\n"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	
}	t_win;

void	ft_destroy(t_win *window);
int		esc_exit(int keysym, t_win *window);
int		cross_exit(t_win *window);
int	create_window(t_win *window, char *str);

void	map_check(char *str, t_win *window);
char	*error_name(char *str);

#endif