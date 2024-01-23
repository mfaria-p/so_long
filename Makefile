# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 17:28:13 by mfaria-p          #+#    #+#              #
#    Updated: 2024/01/23 18:06:27 by mfaria-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJS = $(SRCS:.c=.o)

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L. lXext -L. lX11
RM = rm -f

LIBFT_PATH = ./libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./libraries/minilibx-linux
MINILIBX = $(MINILIBX_PATH)/liblmx_Linux.a

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
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

