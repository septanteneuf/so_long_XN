NAME		=	libftprintf.a

CC			=	gcc

SRCS		=	ft_cs%.c ft_diu.c ft_printf.c ft_ptr.c ft_xX.c \

OBJS		=	${SRCS:.c=.o}

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar crs ${NAME} ${OBJS}

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
