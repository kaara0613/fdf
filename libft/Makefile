# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42.jp>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:00:03 by kaara             #+#    #+#              #
#    Updated: 2025/04/26 10:35:51 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_LIBFT_SRCS = \
	ft_libft/ft_atoi.c\
	ft_libft/ft_memchr.c\
	ft_libft/ft_split.c\
	ft_libft/ft_strncmp.c \
	ft_libft/ft_bzero.c\
	ft_libft/ft_memcmp.c\
	ft_libft/ft_strchr.c\
	ft_libft/ft_strnstr.c\
	ft_libft/ft_calloc.c\
	ft_libft/ft_memcpy.c\
	ft_libft/ft_strdup.c\
	ft_libft/ft_strrchr.c\
	ft_libft/ft_isalnum.c\
	ft_libft/ft_memmove.c\
	ft_libft/ft_striteri.c\
	ft_libft/ft_strtrim.c\
	ft_libft/ft_isalpha.c\
	ft_libft/ft_memset.c\
	ft_libft/ft_strjoin.c\
	ft_libft/ft_substr.c\
	ft_libft/ft_isascii.c\
	ft_libft/ft_putchar_fd.c\
	ft_libft/ft_strlcat.c\
	ft_libft/ft_tolower.c\
	ft_libft/ft_isdigit.c\
	ft_libft/ft_putendl_fd.c\
	ft_libft/ft_strlcpy.c\
	ft_libft/ft_toupper.c\
	ft_libft/ft_isprint.c\
	ft_libft/ft_putnbr_fd.c\
	ft_libft/ft_strlen.c\
	ft_libft/ft_itoa.c\
	ft_libft/ft_putstr_fd.c\
	ft_libft/ft_strmapi.c\

LIST_SRC = \
	list/list_int_insert_at.c\
	list/list_int_pop_at.c\
	list/list_int_pop_back.c\
	list/list_int_pop.c\
	list/list_int_print.c\
	list/list_int_push.c\
	list/list_int_rev_rotate.c\
	list/list_int_rotate.c\
	list/list_int_clone.c\
	list/list_int_access_at.c\
	list/list_void_clear.c\
	list/list_int_sort.c\
	list/list_int_count.c\

FT_PRINTF_SRC = \
	ft_printf/handle_format.c\
	ft_printf/hex_handle_format2.c\
	ft_printf/libftprintf.c\
	ft_printf/d_handle_format.c\
	ft_printf/d_hex_handle_format.c\
	ft_printf/d_libftprintf.c\

GNL_SRC = \
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\

SRCS = \
	$(FT_LIBFT_SRCS)\
	$(LIST_SRC)\
	$(FT_PRINTF_SRC)\
	$(GNL_SRC)\

TEST_FILE = 

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Iinclude -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full

AR = ar rcs
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} -I include ${CFLAGS} -c $< -o $@

test: ${NAME}
	${CC} ${CFLAGS} -I include $(TEST_FILE) libft.a -o test_exec && ${VALGRIND} ./test_exec

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
