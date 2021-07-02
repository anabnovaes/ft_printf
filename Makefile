# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 09:54:26 by apaula-b          #+#    #+#              #
#    Updated: 2021/07/01 22:03:16 by apaula-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC= gcc

HEADER = ft_printf.h

TYPES = ./get_types/

CONVERSIONS  = ./conversions/


#flags to compile
FLAGS = -Wall -Wextra -Werror

FILES = ${TYPES}ft_isalnum.c \
		${TYPES}ft_isalpha.c \
		${TYPES}ft_isascii.c \
		${TYPES}ft_isdigit.c \
		${TYPES}ft_isflag.c \
		${TYPES}ft_isalpha.c \
		${CONVERSIONS}ft_atoi.c \
		${CONVERSIONS}ft_itoa.c \
		${CONVERSIONS}ft_toupper.c \
		ft_printf.c \
		ft_get_flags.c \



OBJ = $(FILES:.c=.o)



#1st rule to execute
all: $(NAME)

#rule name
$(NAME): $(OBJ) $(HEADER)
		ar -rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		$(CC) $(FLAGS) -c $(FILES)

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.a

re: fclean all

.PHONY: all clean fclean re
