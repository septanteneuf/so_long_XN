CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address -Wdeprecated-declarations

NAME	=	so_long 

SRC		=	src/so_long.c \
			src/check_collect.c \
			src/check_errors.c \
			src/check_error_square.c \
			src/exit_game.c \
			src/init_img.c \
			src/moves.c \
			src/paint.c \
			src/update_map.c \

OBJ 	=	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME) : 	$(OBJ)
#			make -C mlx
			make -C ft_printf
			make -C libft
			$(CC) $(CFLAGS) $(SRC) ft_printf/libftprintf.a libft/libft.a mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o : %.c
# 			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
#			make clean -C mlx
			make clean -C ft_printf
			make clean -C libft
			rm -f $(OBJ)

fclean : 	clean
			make fclean -C ft_printf
			make fclean -C libft
			rm -f $(NAME)

re :		fclean all

.PHONY: 	all clean fclean re