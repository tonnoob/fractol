# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 06:17:49 by osousa-d          #+#    #+#              #
#    Updated: 2026/01/26 07:01:53 by otton-sousa      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Llibs/minilibx-linux -lm -ldl -lX11 -lXext

SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/coloring.c \
      $(SRC_DIR)/error.c \
      $(SRC_DIR)/fractal_iter.c \
      $(SRC_DIR)/hooks.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/main.c \
      $(SRC_DIR)/mapping.c \
      $(SRC_DIR)/parser.c \
      $(SRC_DIR)/render.c

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

INCLUDES = -Iincludes -Ilibs/libftprintf/ft_printf -Ilibs/libftprintf/libft

LIBFTPRINTF_DIR = libs/libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(OBJ) $(MLXFLAGS) -L$(LIBFTPRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
