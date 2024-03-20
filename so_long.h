/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:21:39 by phwang            #+#    #+#             */
/*   Updated: 2024/03/20 20:43:53 by phwang           ###   ########.fr       */
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
# define ERROR_MAP_NAME "Map name/extension has error !\n"

typedef struct s_long
{
	void	*mlx_ptr;
	void	*win_ptr;
	
}	t_long;


/*escape*/
int		esc_exit(int keysym, t_long *solong);
int		cross_exit(t_long *solong);

/*solong*/
int		create_window(t_long *solong, char *str);
void	ft_destroy(t_long *solong);

/* map_check */
void	map_check(int argc, char **argv, t_long **solong);
void	error_name(char *str, t_long *so_long);
int put_in_one_bigline(char *map_name, char **big_line_map);
char    *ft_strjoin_solong(char *backup, char *buffer);

/* map_error */
void	handle_error_free(t_long *so_long);
void	msg_error(char *error_msg, t_long *so_long);

#endif