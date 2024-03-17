/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/17 22:52:12 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include "LIBFT_PERSO/ft_printf/ft_printf.h"
# include "LIBFT_PERSO/get_next_line.h"
# include "LIBFT_PERSO/libft.h"
# include "minilibx_opengl/minilibx_opengl_20191021/mlx.h"
// # include "minilibx_opengl/minilibx_opengl_20191021/mlx_int.h"
// # include "minilibx_opengl/minilibx_opengl_20191021/mlx_new_window.h"
// # include "minilibx_opengl/minilibx_opengl_20191021/mlx_opengl.h"
// # include "minilibx_opengl/minilibx_opengl_20191021/mlx_png.h"

# define ERROR -1
# define ERROR_MSG "Error\n"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_win;

void	ft_destroy(t_win window);
int		handle_input_key(int keysym, t_win *window);
int		handle_mouse_esc(t_win *window);
t_win	create_window(int height, int width, char *str);

#endif