# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 21:42:08 by maghayev          #+#    #+#              #
#    Updated: 2020/02/29 03:22:28 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
YELLOW = "\033[33m\c"
UNDERLINE = "\033[4m\c"
PURPLE = "\033[35m\c"
NC="\033[0m\c"

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC  = $(call rwildcard,src/,*.c)
LIBS = -Iheaders/ -Ilibs/ft_stdio/headers/ -Ilibs/ft_stdio/libs/libft/headers/
ALIBS = libs/ft_stdio/libftprintf.a

OBJECT = $(SRC:.c=.o)

DEPS = ft_stdio/

%.o: %.c
	@echo $(YELLOW)
	$(CC) $(CFLAGS) $(LIBS) -g -o $@ -c $<
	@echo $(NC)

all: $(NAME)

$(NAME): | deps $(OBJECT)
	$(CC) $(CFLAGS) $(LIBS) $(ALIBS) -g main.c $(OBJECT)

deps: makedep
	@echo $(UNDERLINE)
	@echo "Finished building Dep. Libriaries"
	@echo $(NC)

clean: cleandep
	@echo $(YELLOW)
	@echo "ft_ls clean started"
	@/bin/rm -f $(OBJECT)
	@echo $(NC)
	@echo "..........."
	@echo $(YELLOW)
	@echo "ft_ls clean finished"
	@echo $(NC)

fclean: clean
	@make fclean -C libs/ft_stdio/
	@/bin/rm -f $(NAME)
	@echo "stdio has been deleted! *sign*"

re: fclean all

makedep: libs/$(DEPS)
	@make -C $<
	@echo $(NC)

cleandep: libs/$(DEPS)
	@make clean -C $<

.PHONY: stdiomake all clean fclean re
