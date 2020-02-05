# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 21:42:08 by maghayev          #+#    #+#              #
#    Updated: 2020/02/03 21:53:28 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
ORANGE = "\033[33m\c"
PURPLE = "\033[35m\c"
NC="\033[0m\c"
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = libs/ft_stdio/ft_stdio.h
SRC  = $(wildcard src/*.c)

ROOTLIBS = libs/ft_stdio/libftprintf.a

OBJECT = $(SRC:.c=.o) $(SRCH:.c=.o)

%.a: stdiomake
	@echo $(PURPLE)
	@echo "Finished building Dep. Libriaries"
	@echo $(NC)

%.o: %.c $(DEPS)
	@echo $(ORANGE)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo $(NC)

all: $(NAME)

$(NAME): $(ROOTLIBS) $(OBJECT)
	$(CC) $(CFLAGS) main.c $(OBJECT) $(ROOTLIBS)

stdiomake:
	@make -C libs/ft_stdio/

clean:
	@make clean -C libs/ft_stdio/
	@echo $(PURPLE)
	@echo "whaaaaa, claning printf..."
	@/bin/rm -f $(OBJECT)
	@echo "There! Done!"
	@echo $(NC)

fclean: clean
	@make fclean -C libs/ft_stdio/
	@/bin/rm -f $(NAME)
	@echo "stdio has been deleted! *sign*"

re: fclean all

.PHONY: stdiomake all clean fclean re
