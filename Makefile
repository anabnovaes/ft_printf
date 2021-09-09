# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 09:54:26 by apaula-b          #+#    #+#              #
#    Updated: 2021/09/06 18:03:49 by apaula-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC= gcc

HEADER = ft_printf.h

SOURCE = ./src/

#flags to compile
FLAGS = -Wall -Wextra -Werror

FILES = ft_print_int.c ft_print_char.c ft_print_percent.c ft_printf.c \
		ft_print_string.c ft_print_pointer.c


SRC_FILES = ${SOURCE}ft_atoi.c ${SOURCE}ft_calloc.c ${SOURCE}ft_get_flags.c \
			${SOURCE}ft_get_types.c ${SOURCE}ft_itoa.c ${SOURCE}ft_start_functions.c \
			${SOURCE}ft_sizes.c ${SOURCE}ft_toupper.c ${SOURCE}ft_putchar.c

OBJ = $(FILES:.c=.o) ft_atoi.o ft_calloc.o ft_get_flags.o ft_get_types.o ft_itoa.o \
		ft_start_functions.o ft_sizes.o ft_toupper.o ft_putchar.o \
	

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

.PHONY: all clean fclean re
