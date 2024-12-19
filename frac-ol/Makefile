# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 17:51:21 by mmarinov          #+#    #+#              #
#    Updated: 2024/12/19 16:03:03 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
END      = \033[0m
YELLOW   = \033[0;93m
GREEN    = \033[0;32m
RED      = \033[0;91m
CYAN     = \033[0;96m
BLUE     = \033[0;94m

# Program name
NAME = fractol

# Sources
SRC_PATH   = src/
SRC        = fractol.c \
            render.c \
            utils.c \
            events.c \
            colors.c \
            fractol_creation.c \
            parse_args.c \
			support_message.c \
            fractal_func/mandelbrot.c \
            fractal_func/julia.c \
            fractal_func/mandelbox.c \
            fractal_func/burning_ship.c \
            fractal_func/tricorn.c \
            colors/color_beta.c \
            colors/color_mix.c \
            colors/color_patterns.c
SRCS       = $(addprefix $(SRC_PATH), $(SRC))

# Object files
OBJ_DIR    = objs
OBJS       = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Library paths
LIBFT_DIR  = ./libft
LIBFT_LIB  = $(LIBFT_DIR)/libft.a
LIBFT_INC  = -I$(LIBFT_DIR)/includes

# Compiler and flags
CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -I./includes -I$(MLX_DIR) $(LIBFT_INC)

# Minilibx paths and flags
MLX_DIR    = minilibx-linux
MLX_LIB    = $(MLX_DIR)/libmlx.a
MLX_FLAGS  = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Remove command
RM         = rm -rf

# Default rule
all: $(NAME)

# Build the executable
$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_LIB)
	@echo "$(YELLOW)Executable $(NAME) created successfully!$(END)"

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/fractal_func $(OBJ_DIR)/colors
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(BLUE)Libft compiled successfully!$(END)"

# Build MinilibX
$(MLX_LIB):
	@if [ ! -f $(MLX_LIB) ]; then \
		make --no-print-directory -C $(MLX_DIR) > /dev/null 2>&1; \
		echo "$(BLUE)MinilibX compiled successfully!$(END)"; \
	else \
		echo "$(BLUE)MinilibX already compiled, skipping...$(END)"; \
	fi

# Clean object files and dependencies
clean:
	@$(RM) $(OBJ_DIR)
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@echo "$(BLUE)Cleaned up object and dependency files.$(END)"

# Full clean (removes executable and object files)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR) > /dev/null
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@echo "$(RED)Executable $(NAME) removed.$(END)"

# Rebuild everything
re: fclean all
	@echo "$(CYAN)Everything clean & recompiled!$(END)"

.PHONY: all clean fclean re
