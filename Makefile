NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -lm -lmlx -framework OpenGL -framework AppKit #-fsanitize=address
RM		= rm -fr
SRC		= main.c check_character.c print_map.c \
		  check_file_path.c check_walls.c get_map.c \
		  map_dup.c free_game.c check_path.c \
		  render_game.c update_player.c get_pos.c \
		  event_handle.c close_window.c

SRC		:= $(addprefix src/, $(SRC))

LIBFT	= ./libft/

LIB		= ./libft/libft.a

all: $(LIB) $(NAME)

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
