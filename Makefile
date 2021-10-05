# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 09:54:26 by apaula-b          #+#    #+#              #
#    Updated: 2021/10/05 19:21:40 by apaula-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC= gcc

HEADER = ft_printf.h

SRC = ./src/

#flags to compile
FLAGS = -Wall -Wextra -Werror

FILES = ft_print_int.c ft_print_percent.c ft_printf.c ft_print_string.c \
		ft_print_pointer.c ft_print_hexa.c


SRC_FILES = ${SRC}ft_atoi.c ${SRC}ft_calloc.c  ${SRC}ft_conversions.c\
			${SRC}ft_get_types.c ${SRC}ft_itoa.c  \
			${SRC}ft_putchar.c ${SRC}ft_sizes.c ${SRC}ft_start_functions.c \
			${SRC}ft_utoa_long.c ${SRC}ft_utoa.c

OBJ = $(FILES:.c=.o) ft_atoi.o ft_calloc.o ft_conversions.o \
		ft_get_types.o ft_itoa.o ft_putchar.o ft_sizes.o ft_start_functions.o \
		ft_utoa_long.o ft_utoa.o

#1st rule to execute
all: $(NAME)

#rule name
$(NAME): $(OBJ) $(HEADER)
		ar -rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		$(CC) $(FLAGS) -c $(FILES) $(SRC_FILES)

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.a

re: fclean all

bonus: all

.PHONY: all clean fclean re
