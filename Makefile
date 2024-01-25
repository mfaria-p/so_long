# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 17:28:13 by mfaria-p          #+#    #+#              #
#    Updated: 2024/01/25 20:23:20 by mfaria-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/error_handling/errors.c \
       srcs/init/data_init.c \
       srcs/init/game_init.c \
       srcs/map_check/map_verifier.c \
       srcs/map_check/path_verifier.c \
       srcs/map_check/read_map.c \
       main.c

OBJS = $(SRCS:.c=.o)

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lXext -lX11

LIBFT_PATH = ./libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./libraries/minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MINILIBX):
	make -C $(MINILIBX_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

