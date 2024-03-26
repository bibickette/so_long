/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/26 22:35:16 by phwang           ###   ########.fr       */
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
void	msg_error(char *error_msg, int msgflag);
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


/*background*/
int background_creation(t_long *so_long);
void put_img(t_long *so_long, t_img *whatimg, int where_x, int where_y);
void	set_background(t_long *so_long);
void choose_img(t_long *so_long, int *x, int *y);
/*img_error*/
void free_background(t_long *so_long);
void apocalypse(t_long *so_long);

/* free_tiles */
void free_tiles(t_long *so_long);

/* tiles*/
int set_tiles(t_long *so_long);
int	load_n_set(t_long *so_long, char **dico);
t_img	*search_img(t_long *so_long, char *img_wanted);
void	put_outside(t_long *so_long, int *x, int *y);
void	put_inside(t_long *so_long, int *x, int *y);

#endif