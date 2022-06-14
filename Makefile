YELLOW	:= $(shell tput -Txterm setaf 3)
GREEN	:= $(shell tput -Txterm setaf 2)
RED		:= $(shell tput -Txterm setaf 1)
RESET	:= $(shell tput -Txterm sgr0)

NAME	= so_long

OBJS	= ${SRCS:.c=.o}
SRC		= main.c check_map.c so_long_utils.c start.c move.c make_map.c put_stuff.c ft_split.c write_move.c move_player_2.c
SRCS	= ${addprefix src/, ${SRC}}

CFLAGS	= -Wall -Wextra -Werror -g
CC		= gcc

HEADER	= so_long.h


%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@printf "${YELLOW}Compiling [%s]...%-42s${RESET}\r" $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\n${GREEN}Finished : $(NAME)${RESET}"

all:	${NAME}

clean:
		@rm -rf ${OBJS}
		@echo "${RED}Removing objects...${RESET}"

fclean:	clean
		@rm -rf ${NAME}
		@echo "${RED}Removing ${NAME}...${RESET}"

re:		fclean all

.PHONY : all clean fclean re