# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 22:31:44 by phwang            #+#    #+#              #
#    Updated: 2024/03/22 21:09:17 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src/*
OBJ_DIR = obj

LIBFT = -L./LIBFT_PERSO -lft
MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = \
	map_check_obj.c \
	map_set.c \
	map_check.c \
	map_error.c \
	window.c \
	escape.c \
	main.c 

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
	
.PHONY: all clean fclean re git

all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C LIBFT_PERSO
	@make -s -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)

clean:
	@make -s -C LIBFT_PERSO clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C LIBFT_PERSO fclean
	@rm -f $(NAME)

re:	fclean all

git:
	git add Makefile so_long.h src/* maps/*
	git commit -m "maj"
	git push
	git status
