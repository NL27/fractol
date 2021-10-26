# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 12:25:12 by nlenoch           #+#    #+#              #
#    Updated: 2021/10/21 10:20:39 by nlenoch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

LIBS = -lmlx -Lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -O3

MLX_DIR = ./mlx

SRC = atod.c atoi.c coordinates.c create.c fract_ol.c hooks.c init.c mandelbrot.c split.c utils.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C $(MLX_DIR)
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
		rm -rf $(OBJ)
		rm -rf $(NAME)

fclean: clean
		make -C $(MLX_DIR) clean

re:
		make fclean
		make all
