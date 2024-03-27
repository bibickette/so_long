# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 22:31:44 by phwang            #+#    #+#              #
#    Updated: 2024/03/27 21:31:23 by phwang           ###   ########.fr        #
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
	move.c \
	backup_bgrd.c \
	foreground.c \
	handle_key.c \
	bgrd_image.c \
	bgrd_tiles.c \
	free_all.c \
	background.c \
	map_check_obj.c \
	map_set.c \
	map_check.c \
	map_error.c \
	window.c \
	main.c 

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
	
#PROGRESS BAR
TOTAL_SRCS := $(words $(SRC))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[0;35m
COLOR_BLUE = \e[0;35m

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects The Legend of Solong: $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♣"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(COLOR_BLUE)\nCompiling The Legend of Solong...$(COLOR_RESET)"
	@make -s -C LIBFT_PERSO
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJ) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)
	@echo "$(COLOR_GREEN)The Legend of Solong is ready to begin !$(COLOR_RESET)        "

clean:
	@make -s -C LIBFT_PERSO clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting The Legend of Solong... ✘✘✘$(COLOR_RESET)"
	@make -s -C LIBFT_PERSO fclean
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)✘✘✘ The Legend of Solong fcleaned ! ✘✘✘$(COLOR_RESET)        "


re:	fclean all
