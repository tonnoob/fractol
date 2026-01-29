# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 09:44:04 by otton-sousa       #+#    #+#              #
#    Updated: 2026/01/29 01:15:24 by osousa-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/*.o

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(FT_PRINTF)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make --no-print-directory -C $(FT_PRINTF_DIR)

clean: 
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@make --no-print-directory clean -C $(FT_PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@make --no-print-directory fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
