/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 21:09:07 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_struct.h"

/* FREE_ALL */
void	apocalypse(t_long *so_long);
void	free_tiles(t_long *so_long);
void	ft_destroy(t_long *solong);

/* HANDLE_KEY */
int		cross_exit(t_long *solong);
int		handle_key(int keysym, t_long *so_long);
void	handle_end(t_long *so_long);

/* MOVE */
void	move_up(t_long *so_long);
void	move_down(t_long *so_long);
void	move_left(t_long *so_long);
void	move_right(t_long *so_long);

/* MAP_SET */
void	set_map(int argc, char **argv, t_long *solong);
int		put_in_one_bigline(char *map_name, char **big_line_map);
char	*long_join(char *backup, char *buffer);
char	*heedz_join(char *str, char *backup, char *buffer);

/* MAP_ERROR */
void	msg_error(char *error_msg);
void	map_free(t_long *so_long, int nb_tab);

/* MAP_CHECK */
void	check_map(t_long *so_long);
void	check_path_name(char *str);
int		check_map_len(t_long *so_long);
int		check_map_walls(t_long *so_long);

/* MAP_CHECK_OBJ */
int		check_nb_item(t_long *so_long);
int		check_collectable(t_long *so_long);
void	check_player_exit(t_long *so_long, int *x, int *y);

/* FOREGROUND */
void	set_foreground(t_long *so_long);
void	put_collectable(t_long *so_long);
void	step_n_item(t_long *so_long, int x, int y);

/* BGRD_TILES */
int		set_tiles(t_long *so_long);
int		load_n_set(t_long *so_long, char **dico);

/* BGRD_IMG */
void	put_img(t_long *so_long, t_img *whatimg, int where_x, int where_y);
t_img	*search_img(t_long *so_long, char *img_wanted);

/* BACKUP_BGRD */
int		set_backup_bgrd(t_long *so_long);
void	cpy_background(t_long *so_long);
void	put_backup(t_long *so_long, int where_x, int where_y);

/* BACKGROUND */
int		background_creation(t_long *so_long);
void	set_background(t_long *so_long);
void	put_inside(t_long *so_long, int *x, int *y);
void	put_outside(t_long *so_long, int *x, int *y);

/* WINDOW */
int		create_window(t_long *solong, char *str);
int		display(t_long *so_long);

#endif