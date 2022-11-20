NAME = push_swap

SRC = main.c

RED	= '\033[1;31m'
GREEN	= '\033[1;32m'
BLUE	= '\033[1;34m'
WHITE	= '\033[1;37m'

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"Generating enforcible..."$(WHITE)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"$(NAME) Generated!"$(WHITE)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo $(RED)"OBJS were deleted"$(WHITE)

fclean: clean
	rm -f $(NAME)
	@echo $(RED)"$(NAME) deleted"$(WHITE)

re: fclean all

n:
	"norminette" $(SRC) push_swap.h
