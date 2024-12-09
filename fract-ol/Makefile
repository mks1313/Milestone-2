# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 17:51:21 by mmarinov          #+#    #+#              #
#    Updated: 2024/12/09 18:54:34 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors 
END      = \e[0m
YELLOW   = \033[0;93m
GREEN    = \033[0;32m
RED      = \033[0;91m
CYAN     = \033[0;96m
BLUE     = \033[0;94m

NAME = fractol

SRCS = main.c mandelbrot.c
OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = I$(LIBFT_DIR)/includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

RM = rm -rf

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_LIB)
	@echo "$(YELLOW)Ejecutable $(NAME) created successfully!$(END)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(END)"

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(BLUE)Libft compiled successfully!$(END)"


$(MLX_LIB):
	@if [ ! -f $(MLX_LIB) ]; then \
		make --no-print-directory -C $(MLX_DIR) > /dev/null 2>&1; \
		echo "$(BLUE)MinilibX is compiled successfully!$(END)"
	else \
		echo "$(BLUE)Minilibx already compiled, skipping...$(END)"; \
		fi

flean:
	@$(RM) $(OBJ_DIR)
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@echo "$(BLUE) Cleaned up object and dependency files.$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR) > /dev/null
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@echo "$(RED)Executable $(NAME) removed.$(END)"

re: fclean all
	@echo "$(CYAN)Everything clean & recompiled!$(END)"

.PHONY: all clean fclean re
