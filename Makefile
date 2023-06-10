NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -lm -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address 
RM		= rm -fr
SRC		= main.c


SRC		:= $(addprefix src/, $(SRC))

LIBFT	= ./libft/libft.a

$(NAME): all


$(NAME):
	$(CC) -o $@ $(LIBFT) $(CFLAGS) $(SRC)
clean:
	$(RM)
fclean:
	$(RM)

re: fclean all

.PHONY: all clean fclean re
