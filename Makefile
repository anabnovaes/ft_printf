# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 09:54:26 by apaula-b          #+#    #+#              #
#    Updated: 2021/06/19 20:38:53 by AnaNovaes-M      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC= gcc

HEADER = ft_printf.h

#flags to compile
FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
		./utils/*.c

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
