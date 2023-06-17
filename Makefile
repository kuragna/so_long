NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address -lm -lmlx -framework OpenGL -framework AppKit
RM		= rm -fr
SRC		= main.c check_c_e_p.c print_map.c \
		  check_file_path.c check_walls.c


SRC		:= $(addprefix src/, $(SRC))

LIBFT	= ./libft/

LIB		= ./libft/libft.a

all: $(NAME)

$(LIB):
	make -C $(LIBFT)
$(NAME): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIB)
clean:
	make clean -C $(LIBFT)
fclean:
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re LIB
