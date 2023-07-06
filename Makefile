NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 -lmlx -framework OpenGL -framework AppKit -fsanitize=address
RM			= rm -fr
SRC			= main.c check_character.c print_map.c \
			  check_file_path.c check_walls.c get_map.c \
			  map_dup.c free_game.c check_path.c \
			  render_game.c update_player.c get_pos.c \
			  get_images.c print_error.c start_game.c \

SRC_BONUS 	= main.c check_file_path.c check_character.c \
			  get_map.c print_error.c check_walls.c \
			  get_pos.c get_images.c start_game.c \
			  render_game.c update_player.c check_path.c \
			  map_dup.c animate_enemy.c


SRC_BONUS 	:= $(addprefix bonus/src/, $(SRC_BONUS))

SRC			:= $(addprefix mandatory/src/, $(SRC))

LIBFT		= ./libft/

LIB			= ./libft/libft.a

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBFT)

bonus: $(SRC_BONUS) $(LIB)
	$(CC) -o $(NAME) $(CFLAGS) $^ $(LIB)

$(NAME): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LIB)
clean:
	make clean -C $(LIBFT)
fclean:
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re LIB bonus
