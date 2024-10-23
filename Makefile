# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 14:37:50 by mmarinov          #+#    #+#              #
#    Updated: 2024/10/23 17:37:42 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC = input_validation.c push.c push_swap.c reverse_rotate.c stack.c rotate.c \
      utils.c

# Directorio para archivos objeto
OBJ_DIR = ./obj

# Archivos objeto en el directorio especificado
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = ../libft/libft.h push_swap.h

# Colores
GREEN_DARK = \033[0;32m    # Verde oscuro
WHITE = \033[0m            # Blanco
RED = \033[0;91m           # Rojo
RESET = \033[0m            # Reiniciar color

all: libs $(NAME)

libs:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN_DARK)Executable $(NAME) created successfully!$(RESET)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Regla para crear los archivos objeto en el directorio
$(OBJ_DIR)/%.o: %.c $(INCLUDE) Makefile
	@mkdir -p $(OBJ_DIR)  # Crear el directorio si no existe
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN_DARK)Compiled: $<$(RESET)"  # Mensaje al compilar

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)  # Eliminar el directorio de objetos
	@echo "$(RED)Cleaned up object files.$(RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

