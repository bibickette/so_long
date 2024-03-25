/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:27:32 by phwang            #+#    #+#             */
/*   Updated: 2024/03/25 17:59:00 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "LIBFT_PERSO/libft.h"
# include "minilibx-linux/mlx.h"

# define OK 1
# define ERROR -1
# define ERROR_MSG "Error\n"
# define ERROR_MAP_NAME "Map name/extension/path has error !\n"
# define ERROR_MAP_CONTENT "Map content has error !\n"

# define IMG_WIDTH 75
# define IMG_HEIGHT 75

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define DOOR 'E'
# define ITEM 'C'

# define BUSH	"img/xpm/bush.xpm"
# define FENCE	"img/xpm/fence.xpm"
# define COLLECTABLE	"img/xpm/collectable_.xpm"
# define P_UP	"img/xpm/p_up.xpm"
# define P_DOWN	"img/xpm/p_down.xpm"
# define P_LEFT	"img/xpm/p_left.xpm"
# define P_RIGHT	"img/xpm/p_right.xpm"
# define EXIT_CLOSE	"img/xpm/exit_close.xpm"
# define EXIT_OPEN	"img/xpm/exit_open.xpm"
# define FLOOR_PLAIN	"img/xpm/floor_plain.xpm"
# define FLOOR_DIRT	"img/xpm/floor_dirt.xpm"
# define FLOOR_FLOWER	"img/xpm/floor_flower.xpm"
# define OUTW_CORNER_LEFT	"img/xpm/outw_corner_left.xpm"
# define OUTW_CORNER_RIGHT	"img/xpm/outw_corner_right.xpm"
# define OUTW_LEFT	"img/xpm/outw_left.xpm"
# define OUTW_LOW	"img/xpm/outw_low.xpm"
# define OUTW_RIGHT	"img/xpm/outw_right.xpm"

typedef struct s_long t_long;
typedef struct s_image t_img;
typedef struct s_tilesheet t_tiles;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tilesheet
{
	t_img	bush;
	t_img	fence;
	t_img	collectable;
	t_img	p_up;
	t_img	p_down;
	t_img	p_left;
	t_img	p_right;
	t_img	exit_close;
	t_img	exit_open;
	t_img	floor_plain;
	t_img	floor_dirt;
	t_img	floor_flower;
	t_img	outw_corner_left;
	t_img	outw_corner_right;
	t_img	outw_left;
	t_img	outw_low;
	t_img	outw_right;
}	t_tiles;

typedef struct s_long
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	int		map_size;
	int		map_len;

	t_img		background;
	t_tiles 	tiles;
	
	int		collectable;

}	t_long;

#endif