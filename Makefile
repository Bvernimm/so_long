NAME	= so_long

OBJS	= ${SRCS:.c=.o}
SRC		= main.c check_map.c so_long_utils.c start.c move.c make_map.c put_stuff.c ft_split.c write_move.c move_player_2.c
SRCS	= ${addprefix src/, ${SRC}}

CFLAGS	= -Wall -Wextra -Werror -g
CC		= gcc

HEADER	= so_long.h


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$(NAME): ${OBJS}

all:	${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY : all clean fclean re