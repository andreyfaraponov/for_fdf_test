# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 13:16:27 by afarapon          #+#    #+#              #
#    Updated: 2018/01/08 19:50:24 by afarapon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -Wall -Wextra -Werror

IDIR = ./includes

CFLAGS = -I$(IDIR)

LIBDIR = ./libft

LIBFT = $(LIBDIR)/libft.a

SRCDIR = src

SRC = main.c \
	window_init.c \
	key_hooks.c \
	get_data_from_file.c \
	make_validation.c

_OBJ = $(SRC:%.c=%.o)

_DEPS = fdf.h

OBJ = $(SRC:.c=.o)

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(NAME): $(LIBFT) $(OBJ)
	@cp libft/libft.a ./$(NAME)
	@CC -o $(NAME) $(OBJ) libft/libft.a -lm -lmlx -framework OpenGL -framework AppKit
	make clean

$(LIBFT):
	@make -C $(LIBDIR)

clean:
	@/bin/rm -rf *.o
	@/bin/rm -rf libft/*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf libft/libft.a

re : fclean all

lin: $(LIBFT) $(OBJ)
	@cp libft/libft.a ./$(NAME)
	@CC -o $(NAME) $(OBJ) libft/libft.a -lm -lmlx -lXext -lX11
