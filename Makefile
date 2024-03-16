# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 22:31:44 by phwang            #+#    #+#              #
#    Updated: 2024/03/16 22:55:51 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
OBJ_DIR = obj

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

CC = cc
C_FLAGS = -Wall -Wextra -Werror

SRC = \
	main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
	
.PHONY: all clean fclean re git

all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C minilibx-linux
	@$(CC) $(C_FLAGS) $(OBJ) $(MINILIBX_FLAGS) -o $(NAME)

clean:
	@make -s -C minilibx-linux clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C minilibx-linux clean
	@rm -f $(NAME)

re:	fclean all

git:
	git add Makefile so_long.h src/*
	git commit -m "maj"
	git push
	git status
