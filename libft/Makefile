CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

SRC			=	ft_strdup.c ft_strjoin.c ft_strlen.c \
				ft_substr.c gnl.c gnl_utils.c \

OBJS		=	${SRC:.c=.o}

all:			$(NAME)

$(NAME):
				$(CC) $(FLAGS) -c $(SRC)
				ar rc $(NAME) ${OBJS}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f $(NAME) ${OBJS}

re:				fclean $(NAME) ${OBJS}

.PHONY: 		all clean fclean re