# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 19:02:48 by mmarinov          #+#    #+#              #
#    Updated: 2024/11/17 20:14:10 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ANSI color codes
END         = \e[0m
BOLD        = \e[1m
UNDER       = \e[4m
REV         = \e[7m

DEF_COLOR   = \033[0;39m
GREEN       = \033[0;92m
MAGENTA     = \033[0;95m
CYAN        = \033[0;96m
BLUE        = \033[0;94m
YELLOW      = \033[0;93m
RED         = \033[0;91m

GREEN_DARK = \033[0;32m    # Verde oscuro
WHITE = \033[0m            # Blanco
RED = \033[0;91m           # Rojo



NAME = pipex
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -MMD
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente
SRC = $(SRC_DIR)/pipex.c \
      $(SRC_DIR)/utils_pipex.c \

# Archivos objeto generados
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Archivos de dependencia
DEP = $(OBJ:.o=.d)

# Inclusión de archivos de dependencia
-include $(DEP)

INCLUDE = $(LIBFT_DIR)/libft.h $(SRC_DIR)/pipex.h

# ---------------------------------------------------------------------------- #
#                             Reglas de compilación                            #
# ---------------------------------------------------------------------------- #

# Regla por defecto: compilar el proyecto principal
all: libs $(NAME)

libs:
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)Libft compiled successfully!$(END)"

# Regla compilar el proyecto principal
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN_DARK)Executable $(NAME) created successfully!$(END)"

# Regla para crear los archivos objeto en el directorio especificado
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) Makefile
	@mkdir -p $(OBJ_DIR)  # Crear el directorio si no existe
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA)Compiled: $<$(END)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@rm -f $(DEP)
	@echo "$(BLUE)Cleaned up object and dependency files.$(END)"

fclean: clean
	@echo "$(RED)Cleaning ejecutables...$(END)"
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(CYAN)Executable $(NAME) removed.$(END)"

# Regla para compilar todo desde cero
re: fclean all
	@echo "$(MAGENTA)Everything clean & recompiled!$(END)"

# ---------------------------------------------------------------------------- #
#                               Fases del Makefile                             #
# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re

