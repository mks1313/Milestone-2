# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 14:37:50 by mmarinov          #+#    #+#              #
#    Updated: 2024/10/31 16:06:12 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -MMD
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente
SRC = $(SRC_DIR)/checkers.c \
      $(SRC_DIR)/fill.c \
      $(SRC_DIR)/complete_stack.c \
      $(SRC_DIR)/ft_utils.c \
      $(SRC_DIR)/make_position.c \
      $(SRC_DIR)/move_stack.c \
      $(SRC_DIR)/operation_r.c \
	  $(SRC_DIR)/operations.c \
      $(SRC_DIR)/order.c \
      $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/utils_algoritmia.c

# Archivos objeto generados
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Archivos de dependencia
DEP = $(OBJ:.o=.d)

# Inclusión de archivos de dependencia
-include $(DEP)

INCLUDE = $(LIBFT_DIR)/libft.h $(SRC_DIR)/push_swap.h

# Colores
GREEN_DARK = \033[0;32m    # Verde oscuro
WHITE = \033[0m            # Blanco
RED = \033[0;91m           # Rojo
RESET = \033[0m            # Reiniciar color

all: libs $(NAME)

libs:
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN_DARK)Libft compiled successfully!$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN_DARK)Executable $(NAME) created successfully!$(RESET)"

# Regla para crear los archivos objeto en el directorio especificado
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) Makefile
	@mkdir -p $(OBJ_DIR)  # Crear el directorio si no existe
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN_DARK)Compiled: $<$(RESET)"  # Mensaje al compilar

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@rm -rf $(OBJ_DIR)  # Eliminar el directorio de objetos
	@rm -f $(DEP)
	@echo "$(RED)Cleaned up object and dependency files.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

