/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/22 22:23:38 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define DOOR 'E'
# define ITEM 'C'

typedef struct s_long
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	int		map_size;
	int		map_len;

	int		collectable;
}	t_long;

/*escape*/
int		esc_exit(int keysym, t_long *solong);
int		cross_exit(t_long *solong);

/*window*/
int		create_window(t_long *solong, char *str);
void	ft_destroy(t_long *solong);

/* map_set */
void	set_map(int argc, char **argv, t_long **solong);
int		put_in_one_bigline(char *map_name, char **big_line_map);
char	*long_join(char *backup, char *buffer);
char	*heedz_join(char *str, char *backup, char *buffer);

/* map_error */
void	msg_error(char *error_msg, t_long *so_long, int msgflag);
void	map_free(t_long *so_long, int nb_tab);

/* map_check */
void	check_map(t_long **so_long);
// definir une taille max mapsize en fonction de la taille des img
void	check_path_name(char *str, t_long *so_long);
int		check_map_len(t_long *so_long);
int		check_map_walls(t_long *so_long);

/* map_check_inside */
int		check_nb_item(t_long *so_long);
int		check_collectable(t_long *so_long);

#endif