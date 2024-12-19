# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:46:31 by kaara             #+#    #+#              #
#    Updated: 2024/12/19 03:58:22 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c\
		map_check.c map_check_u.c \
		make_map.c make_map_u.c \
		render_map.c render_map_u.c
#		minilibx_use.c minilibx_use_u.c\
# render_map.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
