# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:03:07 by gfernand          #+#    #+#              #
#    Updated: 2023/03/13 17:32:21 by gfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c check_nb.c list.c parse.c movements.c sort.c sort_2.c sort_3.c argv_3_5.c

RED		= '\033[1;31m'
GREEN	= '\033[1;32m'
BLUE	= '\033[1;34m'
WHITE	= '\033[1;37m'

OBJS = $(SRC:.c=.o)

LIBFT_PATH = libft/
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@echo $(GREEN)"Generating enforcible..."$(WHITE)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -I $(LIBFT_PATH) -o $(NAME)
	@echo $(GREEN)"$(NAME) Generated!"$(WHITE)

%.o: %.c
	$(CC) $(FLAGS) -I $(LIBFT_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@echo $(RED)"OBJS were deleted"$(WHITE)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo $(RED)"$(NAME) deleted"$(WHITE)

re: fclean all

n:
	"norminette"
