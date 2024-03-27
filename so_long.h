/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/27 19:47:34 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_struct.h"

/*escape*/
int		esc_exit(int keysym, t_long *solong);
int		cross_exit(t_long *solong);

/*window*/
int		create_window(t_long *solong, char *str);
void	ft_destroy(t_long *solong);

/* map_set */
void	set_map(int argc, char **argv, t_long *solong);
int		put_in_one_bigline(char *map_name, char **big_line_map);
char	*long_join(char *backup, char *buffer);
char	*heedz_join(char *str, char *backup, char *buffer);

/* map_error */
void	msg_error(char *error_msg);
void	map_free(t_long *so_long, int nb_tab);

/* map_check */
void	check_map(t_long *so_long);
// definir une taille max mapsize en fonction de la taille des img
void	check_path_name(char *str);
int		check_map_len(t_long *so_long);
int		check_map_walls(t_long *so_long);

/* map_check_inside */
int		check_nb_item(t_long *so_long);
int		check_collectable(t_long *so_long);
void	check_player_exit(t_long *so_long, int *x, int *y);

/*background*/
int background_creation(t_long *so_long);
void put_img(t_long *so_long, t_img *whatimg, int where_x, int where_y);
void	set_background(t_long *so_long);

/*img_error*/
void apocalypse(t_long *so_long);

/* free_tiles */
void free_tiles(t_long *so_long);

/* tiles*/
int set_tiles(t_long *so_long);
int	load_n_set(t_long *so_long, char **dico);
t_img	*search_img(t_long *so_long, char *img_wanted);
void	put_outside(t_long *so_long, int *x, int *y);
void	put_inside(t_long *so_long, int *x, int *y);

void	move_up(t_long *so_long);
void	move_down(t_long *so_long);
void	move_left(t_long *so_long);
void	move_right(t_long *so_long);
int	handle_key(int keysym, t_long *so_long);
int display(t_long *so_long);
void	handle_end(t_long *so_long);
void	step_n_item(t_long *so_long, int x, int y);
void set_foreground(t_long *so_long);
void put_collectable(t_long *so_long);


int	set_backup_bgrd(t_long *so_long);
void	cpy_background(t_long *so_long);
#endif