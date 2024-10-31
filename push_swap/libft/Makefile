# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <mmarinov@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:27:43 by mmarinov          #+#    #+#              #
#    Updated: 2024/10/31 13:50:45 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compilador y flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directorio para archivos .o

OBJ_DIR = ./obj

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_memcpy.c \
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
	ft_calloc.c ft_bzero.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_strmapi.c ft_split.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c ft_printf.c utils_csp.c utils_diuxx.c ft_utoa.c \
	get_next_line.c ft_strndup.c ft_atol.c


# Objetos

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Reglas:

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)Library $(NAME) created successfully!$(RESET)"

# Regla para compilar cada archivo objeto en el directorio obj

$(OBJ_DIR)/%.o: %.c libft.h Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# Limpieza:

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files and directory cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Library $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
