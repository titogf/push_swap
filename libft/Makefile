NAME = libft.a

SRCS =	ft_isdigit.c \
		ft_memset.c \
		ft_isprint.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_memchr.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		

OBJS = ${SRCS:.c=.o}


CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
		${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

n:
	norminette ${SRCS} libft.h

.PHONY: all clean fclean re n
